#include <iostream>
#include <math.h>
#include "matrixchain.hpp"

int main(int argc, char** argv) {
    // MatrixChain chain = Generate(14);
    // std::cout << chain;
    Matrix a = Matrix(1,3);
    Matrix b = Matrix(1,3);
    bool res = (a==b);
    std::cout << res << "\n";
    Matrix c = a;
    std::cout << a << '\n';
    return 0;
}