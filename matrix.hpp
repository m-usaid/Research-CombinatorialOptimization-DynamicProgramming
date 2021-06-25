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