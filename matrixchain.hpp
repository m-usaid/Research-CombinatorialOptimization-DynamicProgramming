#include "matrix.hpp"
#include <vector>

class MatrixChain {
    public:
    std::vector<Matrix> chain;
    int size;

    MatrixChain();
    MatrixChain(std::vector<Matrix>);
    MatrixChain(const MatrixChain&);

    // operator overloading
    friend std::ostream& operator<<(std::ostream& os, const MatrixChain& m_chain);    
    bool operator==(const MatrixChain&);
    bool operator!=(const MatrixChain&);
    MatrixChain& operator=(const MatrixChain&);
};


MatrixChain::MatrixChain() {
    size = chain.size();
}

MatrixChain::MatrixChain(std::vector<Matrix> m_chain) {
    chain = m_chain;
    size = chain.size();
}

MatrixChain::MatrixChain(const MatrixChain& m_chain) {
    chain = m_chain.chain;
    size = chain.size();
}

bool MatrixChain::operator==(const MatrixChain& other) {
    if (this->chain == other.chain && this->size == other.size) {
        return true;
    }
    return false;
}

bool MatrixChain::operator!=(const MatrixChain& other) {
    return !(*this == other);
}

MatrixChain& MatrixChain::operator=(const MatrixChain& other) {
    if (this != &other) {
        this->chain = other.chain;
        this->size = other.size;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const MatrixChain& m_chain) {
    os << "{";
    for (int i=0; i<m_chain.chain.size(); ++i){
        os << m_chain.chain[i];
        if (i != m_chain.chain.size() - 1){
            os << ",";
        }
    }
        os << "}\n";
        return os;
}

// generate random matrix chain
MatrixChain Generate(int n){
        srand(time(0));
        std::vector<Matrix> lst;
        lst.push_back(Matrix(rand(), rand()));
        for (int i = 0; i< n-1; i++){
            lst.push_back(Matrix(lst.back().columns, rand()));
        }
        return MatrixChain(lst);
    }