#include <iostream>
#include <math.h>
#include "matrixchain.hpp"

int main(int argc, char** argv) {
    MatrixChain chain = Generate(14);
    std::cout << chain;
    return 0;
}