#include "matrix.hpp"

class MatrixChain {
    public:
    int size; 
    Matrix* matrices[];

    MatrixChain(int m_size, Matrix* mat[]) {
        size = m_size;
        for (int i=0; i<size; i++) {
            matrices[i] = mat[i];
        }
    }
};