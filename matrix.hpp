// Changelog 30/06/21:  - removed unnecessary pointer usage
//                      - added copy constructor 
// TODO:    - discuss matmul to fix return scene 

#include <iostream>

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

    Matrix(const Matrix &M){
        rows = M.rows;
        columns = M.columns;
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
    Matrix mat_mul(Matrix A) {
        if (this->can_multiply(A)) {
            Matrix out = Matrix(this->rows, A.columns);  
            return out;          
        }
        std::cout << "matrices cannot be multiplied due to " << 
        "incompatible dimensions."; 
    }

    // operator overloading 
    friend std::ostream& operator<<(std::ostream& os, const Matrix& M);
};

std::ostream& operator<<(std::ostream& os, const Matrix& M){
    os << "(" << M.rows << ", " << M.columns << ")";
    return os;
}; 