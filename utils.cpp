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
#include "utils.hpp"

void roundSmallToZero(std::vector<std::vector<double>>& matrix, double tolerance) {
    for(auto& row : matrix) {
        for(auto& element : row) {
            if(std::abs(element) < tolerance) {
                element = 0.0;
            }
        }
    }
}
void print(std::vector<std::vector<double>> d){
    std::cout<<std::endl;

    for(auto i: d){
        for(auto j:i){
            std::cout<<j<<", ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
std::vector<std::vector<double>> Identity(int n){ // Parameter d swapped to n
    std::vector<std::vector<double>> out(n,std::vector<double>(n,0));
    for(int i=0;i<n;i++){
        out[i][i]=1;
    }
    return out;
}
std::vector<std::vector<std::vector<double>>> nMatrix(const std::vector<std::vector<std::vector<double>>>& n){ // Parameter d swapped to n
    std::vector<std::vector<std::vector<double>>> out;
    for(int i=0; i< static_cast<int>(n.at(0).at(0).size()); i++){
        std::vector<std::vector<double>> nMat;
        for(int j=0; j< static_cast<int>(n.size()); j++){
            std::vector<double> row;
            for(int k=0; k< static_cast<int>(n.size()); k++){
                row.push_back(n.at(j).at(k).at(i));
            }
            nMat.push_back(row);
        }
        out.push_back(nMat);
    }
    return out;
}


void rowSum(std::vector<double>& a, std::vector<double>& b, double f){
    for(int i=0; i< static_cast<int>(a.size()); i++){
        a.at(i)+=(f*b.at(i));
    }
}

void rowMultiply(std::vector<double>& a, double f){
    for(int i=0; i< static_cast<int>(a.size()); i++){
        a.at(i)*=f;
    }
}
std::tuple<std::vector<std::vector<double>>,std::vector<std::vector<double>>,std::vector<std::vector<double>>, int> LU(std::vector<std::vector<double>> &M){
    int f=1;
    std::vector<std::vector<double>> U = M;
    std::vector<std::vector<double>> L = Identity(static_cast<int>(U.size()));
    std::vector<std::vector<double>> P = L;
    for(int i=0; i< static_cast<int>(U.size()); i++){
        double max=std::abs(U.at(i).at(i));
        int maxIndex = i;
        for(int j=i+1; j< static_cast<int>(U.size()); j++){
            if(std::abs(U.at(j).at(i))>max){
                max = std::abs(U.at(j).at(i));
                maxIndex = j;
            }
        }
        if(i != maxIndex){
            f*=-1;
            std::swap(U.at(maxIndex),U.at(i));
            std::swap(P.at(maxIndex),P.at(i));
            // Fix: Also swap the L matrix elements that have been computed
            for(int k=0; k<i; k++){
                std::swap(L.at(maxIndex).at(k), L.at(i).at(k));
            }
        }
        for(int j=i+1; j< static_cast<int>(U.size()); j++){
            double m =U.at(j).at(i)/U.at(i).at(i);
            rowSum(U.at(j),U.at(i),-1*m);
            L.at(j).at(i) = m;
        }
    }
    return std::make_tuple(L,U,P,f);
}
void specialMultiply(const specialMatrix &a, const specialMatrix &b, specialMatrix &out){
    for (int i = 0; i < static_cast<int>(a.data.size()); i++){
        for (int j = 0; j < static_cast<int>(a.data.size()); j++){
            for (int k = 0; k < static_cast<int>(a.data.at(0).at(0).size()); k++) {
                int r = 0;
                for (int l = 0; l < static_cast<int>(a.data.size()); l++) r += a.data[l][j][k] * b.data[i][l][k];
                out.data[i][j][k] = r;
            }
        }
    }
}

std::vector<std::vector<double>> inv(std::vector<std::vector<double>> M, bool debug){


    std::tuple t = LU(M);
    auto [L, U, P, f] = LU(M);
    roundSmallToZero(L);
    roundSmallToZero(U);
    roundSmallToZero(P);
    if(debug){
        print(L);
        print(U);
        print(P);
    }
    std::vector<std::vector<double>> lInv = Identity(static_cast<int>(L.size()));

    for(int i=0; i< static_cast<int>(L.size()); i++){
        for(int j=i+1; j< static_cast<int>(L.size()); j++){
            rowSum(lInv[j], lInv[i], -L[j][i]);
        }
    }

    std::vector<std::vector<double>> uInv=Identity(static_cast<int>(M.size()));
    for(int i= static_cast<int>(L.size()) - 1; i>=0; i--){

        rowMultiply(uInv.at(i),1/U.at(i).at(i));
        for(int j=i-1;j>=0;j--){
            rowSum(uInv[j], uInv[i],  -U[j][i]);
        }
    }
    if(debug){
        print(lInv);
        print(uInv);
    }

    M = multiply(P,multiply(lInv,uInv));
    return M;
}
std::vector<std::vector<double>> multiply(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b){
    std::vector<std::vector<double>> out = Identity(static_cast<int>(a.size()));
    for(int i=0; i< static_cast<int>(b.size()); i++){
        for(int j=0; j< static_cast<int>(a.size()); j++){
            double sum = 0;
            for(int k=0; k< static_cast<int>(b.size()); k++){
                sum+=(a[k][j]*b[i][k]);
            }
            out[i][j] = sum;
        }
    }
    return out;
}
