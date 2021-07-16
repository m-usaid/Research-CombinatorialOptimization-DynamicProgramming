#include <iostream>
#include "matrixchain.hpp"

// TODO:    -- Create subchains by indexing from chain  
//          -- fix subproblem generation --> generate rigid pairs
//          -- discuss implementation of DAG and solving methods 

class subproblem{
    int sub_size;
    std::vector<subproblem> subproblist; // change to rigid pairs 
    MatrixChain mainChain;
    MatrixChain subchain; 

    public:
    int i, j;

    subproblem();
    subproblem(int, int, const MatrixChain&);
    subproblem(const subproblem&);
    void create_subchain();
    void generate_subproblems();
    void print_self();
    void print_next_layer();
    void print_subproblems();

    // operator overloading
    bool operator==(const subproblem&) const;
    subproblem& operator=(const subproblem&);
    friend std::ostream& operator<<(std::ostream& os, const subproblem& sub_prob);    
};

subproblem::subproblem() {

}

subproblem::subproblem(int i, int j, const MatrixChain& m) {
    this->i = i;
    this->j = j;
    sub_size = j - i + 1;
    mainChain = m;
    generate_subproblems();
    create_subchain();
}

subproblem::subproblem(const subproblem& sub1) {
    i = sub1.i;
    j = sub1.j;
    sub_size = sub1.sub_size;
    mainChain = sub1.mainChain;
    generate_subproblems();
    create_subchain();
}


// fix this -> rigid pairs 
void subproblem::generate_subproblems() {
    for (int k=this->i; k < this->j; k++) {
        subproblist.push_back(subproblem(i, k, mainChain));
        subproblist.push_back(subproblem(k+1, j, mainChain));
        }
}

// look at this later 
// issue: not printing recursively 
void subproblem::print_subproblems() {
    // this->print_next_layer();
    this->print_self();
    for (auto &subprob: subproblist) {
        if (subprob.i != subprob.j) {
        subprob.print_next_layer();
        }
    }
}

void subproblem::print_next_layer() {
    std::cout << "Subproblems: [\n"; 
    for (auto &subprob: subproblist) {
        std::cout << subprob << '\n';
    }
    std::cout << "]\n";
}

void subproblem::print_self(){
    std::cout << "(" << this->i << ", " << this->j << ")\n"; 
}

subproblem& subproblem::operator=(const subproblem& sub) {
    if (this == &sub) {
        return *this;
    }
    this->i = sub.i;
    this->j = sub.j;
    this->sub_size = sub.sub_size;
    this->subproblist = sub.subproblist;
    this->subchain = sub.subchain;
    return *this;
}

bool subproblem::operator==(const subproblem& other) const {
    // might have to update later
    if (this->i == other.i && this->j == other.j) {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const subproblem& sub_prob){
    os << "(" << sub_prob.i << ", " << sub_prob.j << ")"; 
    return os;
}


void subproblem::create_subchain() {
    for (int k=this->i; k<=this->j; k++){
        subchain.chain.push_back(mainChain.chain[k-1]);
    }
}