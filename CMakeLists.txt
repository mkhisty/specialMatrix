cmake_minimum_required(VERSION 3.12)
project(specialmatrix_python)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(pybind11 REQUIRED)

# Add the Python module
pybind11_add_module(specialmatrix
    bindings.cpp
    specialMatrix.cpp
    utils.cpp          # Add this line!
)

# Set properties for the module
target_compile_definitions(specialmatrix PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})

# Optional: Set compiler flags for optimization
target_compile_features(specialmatrix PRIVATE cxx_std_17)

# Optional: Add compile flags
if(MSVC)
    target_compile_options(specialmatrix PRIVATE /W4)
else()
    target_compile_options(specialmatrix PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Set the output name to match the module name
set_target_properties(specialmatrix PROPERTIES OUTPUT_NAME "specialmatrix")
