#include <iostream>
#include "matrixchain.hpp"
// #include <algorithm>
// TODO:    -- Create subchains by indexing from chain  
//          -- fix subproblem generation --> generate rigid pairs
//          -- discuss implementation of DAG and solving methods 

class subproblem{
    public:
    //class vars
    int sub_size;
    MatrixChain mainChain;
    MatrixChain subchain; 
    std::vector<subproblem> subproblist; // change to rigid pairs 
    int i, j;

    //methods
    subproblem();
    subproblem(int, int, const MatrixChain&);
    subproblem(const subproblem&);
    void create_subchain();
    void generate_subproblems();
    void print_self();
    void print_next_layer(subproblem sub);
    void print_subproblems();
    bool is_subprob(subproblem& sub);
    std::vector<subproblem> get_all_subprob();
    std::vector<subproblem> get_next_layer();

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
    mainChain = m;
    sub_size = j - i + 1;

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
        subproblist.push_back(subproblem(i, k, this->mainChain));        
        subproblist.push_back(subproblem(k+1, j, this->mainChain));
    }
}

// look at this later 
// issue: not printing recursively 
// void subproblem::print_subproblems() {
//     for (auto &subprob: this->get_all_subprob()) {
//         std::cout << subprob << std::endl;
//         }
// }


// prints immediate subproblems called by current subproblem 
void subproblem::print_next_layer(subproblem sub) {
    std::cout << sub <<": ["; 
    for (auto &subprob: subproblist) {
        std::cout << subprob << ',';
    }
    std::cout << "]\n";
}

void subproblem::print_subproblems() {
    this->print_next_layer(subproblem(this->i, this->j, this->mainChain));
    for (auto &subprob: subproblist) {
        if (subprob.i != subprob.j) {
        subprob.print_next_layer(subprob);
        }
    }
}


void subproblem::print_self(){
    std::cout << "S(" << this->i << ", " << this->j << ")"; 
}

std::vector<subproblem> subproblem::get_all_subprob() {
    std::vector<subproblem> all_probs;
    // for (int x=this->i; x <= this->j; x++) {
    //     for (int y=x; y<this->j; y++) {
    //         all_probs.push_back(subproblem(x, y, this->mainChain));
    //     }
    // }
    // for (auto &subprob: all_probs) {
    //     std::cout << subprob << '\n';
    // }
    all_probs.push_back(subproblem(this->i, this->j, this->mainChain));
    for (auto &subprob: subproblist) {
        // if (subprob.i != subprob.j) {
            for (auto &subprob: subprob.subproblist) {
                all_probs.push_back(subprob);
            }
            
        // }
    }

    // for (auto &subprob: all_probs) {
    //     std::cout << subprob << '\n';
    // }
    return all_probs;
}

bool subproblem::is_subprob(subproblem& sub) {


    for (auto &subprob: this->get_all_subprob()){
        if (subprob == sub) {
            std::cout<< "true" << '\n';
            return true;
       }
    }

    return false;

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
    os << "S(" << sub_prob.i << ", " << sub_prob.j << ")"; 
    return os;
}


void subproblem::create_subchain() {
    for (int k=this->i; k<=this->j; k++){
        subchain.chain.push_back(mainChain.chain[k-1]);
    }
}