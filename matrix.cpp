#include <iostream>
#include <math.h>

class Matrix {    
    public:
    // attributes of matrix: rows & columns 
    int rows;
    int columns;

    // constructors
    Matrix() {
        rows = 0; 
        columns = 0;
    }

    Matrix(int m_rows, int m_columns) {
        rows = m_rows; 
        columns = m_columns;
    }

    // check if matrix can multiply with another matrix
    bool can_multiply(Matrix A) {
        if (this->columns == A.rows){
            return true;
        }
        else {
            return false;
        }
    }

    // multiply two matrices and output another matrix
    Matrix* mat_mul(Matrix A) {
        if (this->can_multiply(A)) {
            Matrix* out = new Matrix(this->rows, A.columns);  
            return out;          
        }
        std::cout << "matrices cannot be multiplied due to " << 
        "incompatible dimensions.";
        return nullptr;
    }
};

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