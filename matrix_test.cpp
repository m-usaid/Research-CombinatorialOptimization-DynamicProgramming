#include <iostream>
#include <math.h>
#include "matrixchain.hpp"

int main(int argc, char** argv) {
    Matrix mat0 = Matrix(4,3);
    Matrix mat1 = Matrix(3,5);
    std::vector<Matrix> lst = {mat0, mat1};
    MatrixChain chain1 = MatrixChain(lst);
    return 0;
}