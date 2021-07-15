#include <iostream>
#include "matrixchain.hpp"


// TODO: - pass subchain and 
class subproblem{
    int sub_size;
    std::vector<subproblem> subproblist;
    MatrixChain subchain; 

    public:
    int i, j;

    subproblem(int, int);

    subproblem(const subproblem&);

    void create_subchain(const MatrixChain&);
    void generate_subproblems();
    void print_subproblems();

    // operator overloading
    void operator=(const subproblem&);
    // friend bool operator==(const subproblem& m1, const subproblem& m2);
    friend std::ostream& operator<<(std::ostream& os, const subproblem& sub_prob);    
};



subproblem::subproblem(int i, int j) {
    this->i = i;
    this->j = j;
    sub_size = j - i + 1;
}

subproblem::subproblem(const subproblem& sub1) {
    i = sub1.i;
    j = sub1.j;
    sub_size = sub1.sub_size;
    // generate subproblems 
    // create subchain and assign 
}

void subproblem::generate_subproblems() {
    for (int k=this->i; k <= this->j; k++) {
        for (int l=k; l<=this->j; l++) {
            if ((k == this->i) && (l == this->j)) {} 
            else {
            subproblist.push_back(subproblem(k, l));
            }
        }
    }
}

void subproblem::print_subproblems() {
    std::cout << "Subproblems: [\n"; 
    for (auto &subprob: subproblist) {
        std::cout << subprob << '\n';
    }
    std::cout << "]\n";
}

std::ostream& operator<<(std::ostream& os, const subproblem& sub_prob){
    os << "(" << sub_prob.i << ", " << sub_prob.j << ")"; 
    return os;
}

// bool operator==(const subproblem& subprob1, const subproblem& subprob2) {
//     if ((subprob1.i == subprob2.i) && (subprob1.j == subprob2.j)){
//         return true;
//     }
//     return false;
// }   