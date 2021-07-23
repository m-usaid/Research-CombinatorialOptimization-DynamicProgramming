#include "subproblem.hpp"
// create function to generate problem instance 

int main(int argc, char** argv){
    MatrixChain mychain = generate_chain(4);
    subproblem subprob = subproblem(1, 4, mychain);
    // subprob.print_subproblems();
    // subproblem subprob1 = subproblem(1,1, generate_chain(1));
    // subprob.get_all_subprob();
    // subprob.is_subprob(subprob1);

    subprob.print_subproblems();

    return 0;    
}