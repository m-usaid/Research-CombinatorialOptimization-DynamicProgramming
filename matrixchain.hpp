// TODO: 

#include "matrix.hpp"
#include <vector>

class MatrixChain {
    public:
    std::vector<Matrix> chain;
    int size;

    MatrixChain() {
        size = chain.size();
    }

    MatrixChain(std::vector<Matrix> m_chain){
        chain = m_chain;
        size = chain.size();
    }

    MatrixChain(const MatrixChain& m_chain){
        chain = m_chain.chain;
        size = chain.size();
    }

    friend std::ostream& operator<<(
        std::ostream& os, const MatrixChain& m_chain
        );
};

std::ostream& operator<<(std::ostream& os, const MatrixChain& m_chain) {
    // implement this using for loop   
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