#include <algorithm>
#include <tuple>
#include <iostream>
#include <ostream>
#include <sys/types.h>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
#include "specialMatrix.hpp"

std::vector<std::vector<double>> multiply(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b);
void roundSmallToZero(std::vector<std::vector<double>>& matrix, double tolerance = 1e-10);
void print(std::vector<std::vector<double>> d);
std::vector<std::vector<double>> Identity(int n);
std::vector<std::vector<std::vector<double>>> nMatrix(const std::vector<std::vector<std::vector<double>>>& n);
void rowSum(std::vector<double>& a, std::vector<double>& b, double f);
void rowMultiply(std::vector<double>& a, double f);
std::tuple<std::vector<std::vector<double>>,std::vector<std::vector<double>>,std::vector<std::vector<double>>, int> LU(std::vector<std::vector<double>> &M);
void specialMultiply(const specialMatrix &a, const specialMatrix &b, specialMatrix &out);
std::vector<std::vector<double>>  inv(std::vector<std::vector<double>> M, bool debug=false);
std::vector<std::vector<double>>  multiply(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b);
