#include "supproblem.hpp"

int main(int argc, char** argv){

    subproblem subprob = subproblem(1, 3);
    // subprob.print_subproblems();
    subprob.generate_subproblems();
    subprob.print_subproblems();
    return 0;
    
}