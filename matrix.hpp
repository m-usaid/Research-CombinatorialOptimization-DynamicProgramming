#include <iostream>

class Matrix {    
    public:
    int rows;
    int columns;

    // constructors
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix&);

    // methods 
    bool can_multiply(const Matrix); // multiplication compatibility
    Matrix mat_mul(Matrix); // multiply two matrices
    
    // operator overloading 
    bool operator==(const Matrix&);
    bool operator!=(const Matrix&);
    Matrix& operator=(const Matrix&);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& M);
};

Matrix::Matrix() {
    rows = 0; 
    columns = 0;
}

Matrix::Matrix(int r, int c) {
    rows = r; 
    columns = c;
}

Matrix::Matrix(const Matrix& M) {
    rows = M.rows;
    columns = M.columns;
}

bool Matrix::can_multiply(const Matrix other) {
    if (this->columns == other.rows) {
        return true;
    }
    return false;
}

Matrix Matrix::mat_mul(Matrix A) {
    Matrix out = Matrix(this->rows, A.columns);  
    return out;   
}

Matrix& Matrix::operator=(const Matrix& m) {
        this->rows = m.rows;
       this-> columns = m.columns;
       return *this;
}

bool Matrix::operator==(const Matrix& other) {
    if ((this->rows == other.rows) && (this->columns == other.columns)) {
        return true;
    }
    return false;
}

bool Matrix::operator!=(const Matrix& other) {
    return !(* this == other);
}

std::ostream& operator<<(std::ostream& os, const Matrix& M){
    os << "(" << M.rows << ", " << M.columns << ")";
    return os;
}