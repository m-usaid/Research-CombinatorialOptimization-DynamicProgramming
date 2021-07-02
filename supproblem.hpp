#include <iostream>

class subproblem{

    int i; 
    int j; 
    subproblem* subprob1;
    subproblem* subprob2;

    public:

    subproblem(int i, int j){
        // if (i > j){
        //     std::cout << "error: i > j" << std::endl;   
        // }
        if (i == j){
            this->i = i;
            this->j = j;
            this->subprob1 = nullptr;
            this->subprob2 = nullptr;
        }
        else{
            this->i = i;
            this->j = j;
            this->subprob1 = new subproblem(i+1, j);
            this->subprob2 = new subproblem(i, j-1);
        }
    }


    int get_i(){
        return this->i;
    }
    
    int get_j(){
        return this->j;
    }

    void printsubprob(){       

        if (this->subprob1 == nullptr && this->subprob2 == nullptr){
            std::cout << "S(" << this->i << ", " << this->j << ")" << std::endl;
                   
        }
        else{
            
            std::cout << "S(" << this->i << ", " << this->j << ")" << std::endl;
            this->subprob1->printsubprob();
            this->subprob2->printsubprob();
        }

    }
    friend bool operator==(subproblem& m1, subproblem& m2);


};

bool operator==(subproblem& m1, subproblem& m2) {
    if ((m1.get_i() == m2.get_i()) && (m1.get_j() == m2.get_j())){
        return true;
    }
    return false;

}   