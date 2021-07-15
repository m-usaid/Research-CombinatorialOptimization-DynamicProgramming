#include "subproblem.hpp"

int main(int argc, char** argv){

    subproblem subprob = subproblem(1, 3);
    subproblem subprob1 = subproblem(1,4);
    if (subprob1 == subprob) {
        std::cout << 1 << '\n';
    }
    else{
        std::cout << 0 << '\n';
    }
    
    // subprob.print_subproblems();
    // subprob.generate_subproblems();
    // subprob.print_subproblems();
    return 0;
    
}