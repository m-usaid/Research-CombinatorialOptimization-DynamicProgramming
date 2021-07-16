#include "matrixchain.hpp"

int main(int argc, char** argv) {
    // MatrixChain chain = Generate(14);
    // std::cout << chain;
    Matrix a = Matrix(1,3);
    Matrix b = Matrix(1,4);

    std::vector<Matrix> matlst;
    matlst.push_back(a);
    matlst.push_back(b);
    
    std::vector<Matrix> matlst2;
    matlst2.push_back(a);
    matlst2.push_back(Matrix(4,4));

    MatrixChain m1 = MatrixChain(matlst);
    MatrixChain m2 = MatrixChain(matlst2);
    std::cout << (m1 == m2) << '\n';
    return 0;
}