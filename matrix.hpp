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
        Matrix out = Matrix(this->rows, A.columns);  
        return out;          
    }

    // operator overloading 
    friend std::ostream& operator<<(std::ostream& os, const Matrix& M);
    friend bool operator==(Matrix& m1, Matrix& m2);

    Matrix& operator=(const Matrix& m) {
        this->rows = m.rows;
       this-> columns = m.columns;
       return *this;
    }

};

std::ostream& operator<<(std::ostream& os, const Matrix& M){
    os << "(" << M.rows << ", " << M.columns << ")";
    return os;
}; 

bool operator==(Matrix& m1, Matrix& m2) {
    if ((m1.rows == m2.rows) && (m1.columns == m2.columns)){
        return true;
    }
    return false;
}