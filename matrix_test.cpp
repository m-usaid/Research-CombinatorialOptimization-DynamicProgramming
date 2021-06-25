#include <iostream>
#include <math.h>
#include "matrixchain.hpp"

int main(int argc, char** argv) {
    Matrix* mat0 = new Matrix(4,3);
    Matrix* mat1 = new Matrix(3,5);
    // std::cout << mat0->can_multiply(*mat1) << '\n';
    Matrix* mat2 = mat0->mat_mul(*mat1);
    Matrix* mats[3] = {mat0, mat1, mat2};
    MatrixChain myChain = MatrixChain(3, mats);
    std::cout << myChain.size << '\n';
    return 0;
}