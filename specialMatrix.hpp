#include <iostream>
#ifndef SPECIALMATRIX_H
#define SPECIALMATRIX_H
#include <vector>
class specialMatrix{
    public:
    std::vector<std::vector<std::vector<double>>> data;
    int n;
    int d;
    std::vector<std::vector<double>> toNormal();
    specialMatrix(int a, int b, bool identity);
    specialMatrix(std::vector<std::vector<std::vector<double>>> v);
    friend std::ostream& operator<<(std::ostream& os, specialMatrix a);
    specialMatrix operator&(const specialMatrix b) const;
    specialMatrix operator^(int b) const;
    specialMatrix operator*(double b) const;
    specialMatrix operator/(double b) const;
    specialMatrix operator+(double b) const;
    specialMatrix operator-(double b) const;
    void apply(double (*f)(double));
    std::vector<std::vector<double>> applyAll(double (*f)(double));
    double det();
};
#endif
