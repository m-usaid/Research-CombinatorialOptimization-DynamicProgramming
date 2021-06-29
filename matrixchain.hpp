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

};