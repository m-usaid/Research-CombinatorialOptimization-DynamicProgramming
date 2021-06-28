#include <iostream>

class Data
{
private:
    int stored;

public:
    Data(int stored){
        this->stored = stored;
    }
    ~Data();
};


class Node
{
private:
    Node* prev;
    Node* next; 
    Data* data;
    bool root_node;
public:

    Node(Node* p = NULL, Node*n, Data* d, bool root_node){

        this->root_node = root_node;
        if (this->root_node == true){
            this->prev = NULL;
            
        }

        this->data = d;

    }
    
    ~Node(){

        this-prev, this->next, this->data = NULL;
        delete this->prev, this->next, this->next;

    }
    
};
