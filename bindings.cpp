#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include <pybind11/iostream.h>
#include <pybind11/functional.h>
#include <sstream>
#include "specialMatrix.hpp"
#include "utils.hpp"  // Include the utils header instead of forward declarations

namespace py = pybind11;

PYBIND11_MODULE(specialmatrix, m) {
    m.doc() = "Python bindings for specialMatrix class";

    // Bind the specialMatrix class
    py::class_<specialMatrix>(m, "SpecialMatrix")
        // Constructors
        .def(py::init<int, int, bool>(),
             "Constructor with dimensions and identity flag",
             py::arg("a"), py::arg("b"), py::arg("identity") = false)
        .def(py::init<std::vector<std::vector<std::vector<double>>>>(),
             "Constructor with 3D vector data",
             py::arg("data"))

        // Public members
        .def_readwrite("data", &specialMatrix::data, "3D data vector")
        .def_readwrite("n", &specialMatrix::n, "n dimension")
        .def_readwrite("d", &specialMatrix::d, "d dimension")

        // Methods
        .def("toNormal", &specialMatrix::toNormal,
             "Convert to normal 2D matrix representation")
        .def("det", &specialMatrix::det,
             "Calculate determinant")
        .def("apply", [](specialMatrix& self, py::function func) {
            // Create a temporary wrapper that can be used with the existing C++ interface
            // We need to store the function and create a static wrapper
            static py::function stored_func;
            stored_func = func;

            auto wrapper = [](double x) -> double {
                return stored_func(x).cast<double>();
            };

            // Use a function pointer version
            double (*func_ptr)(double) = +wrapper;
            self.apply(func_ptr);
        }, "Apply function to all elements in-place", py::arg("function"))
        .def("applyAll", [](specialMatrix& self, py::function func) {
            static py::function stored_func;
            stored_func = func;

            auto wrapper = [](double x) -> double {
                return stored_func(x).cast<double>();
            };

            double (*func_ptr)(double) = +wrapper;
            return self.applyAll(func_ptr);
        }, "Apply function to all elements and return as 2D matrix", py::arg("function"))

        // Operators
        .def("__and__", &specialMatrix::operator&,
             "Matrix multiplication using & operator")
        .def("__matmul__", &specialMatrix::operator&,
             "Matrix multiplication using @ operator")
        .def("__xor__", &specialMatrix::operator^,
             "Matrix power using ^ operator")
        .def("__pow__", &specialMatrix::operator^,
             "Matrix power using ** operator")
        .def("__mul__", &specialMatrix::operator*,
             "Scalar multiplication")
        .def("__truediv__", &specialMatrix::operator/,
             "Scalar division")
        .def("__add__", &specialMatrix::operator+,
             "Scalar addition")
        .def("__sub__", &specialMatrix::operator-,
             "Scalar subtraction")

        // String representation
        .def("__repr__", [](const specialMatrix &m) {
            std::stringstream ss;
            ss << m;
            return ss.str();
        })
        .def("__str__", [](const specialMatrix &m) {
            std::stringstream ss;
            ss << m;
            return ss.str();
        });


}
