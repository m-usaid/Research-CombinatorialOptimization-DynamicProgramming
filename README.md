## Matrix-Chain Multiplication Using Multistage Optimization 
#### To Do:

- `matrix.hpp` 
    - [x] overload ostream, create constructors
    - [x] discuss and fix `Matrix.matmul(Matrix M)` method, figure out 
    problem with return of garbage values. 
    - [x] overload equality operator 

- `matrixchain.hpp`
    - [x] use vectors instead of arrays to represent chain 
    - [x] create default & copy constructors 
    - [x] overload ostream and equality 
    - [x] assignment operator

- 'subproblem.hpp'
    - [x] Recursively generates all subproblems
    - [x] Stores all subproblem
    - [x] = Operator overloaded to check equality between two subproblems
    
- Create DAG that stores all subproblems when generated.

- Read procedure of optimization, make notes, discuss 
    - [ ] create a latex file showing dag and its representation of 
        paranthesizations (usaid)

- Go over implementation of DP solution to MCM 