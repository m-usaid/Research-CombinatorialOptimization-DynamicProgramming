#include <iostream>
#include "subproblem.hpp"

class Node {
    subproblem subprob;
    int cost;

    public: 

    Node(const subproblem& s){
        this->subprob = s;
        this->cost = 0;
    };
    ~Node();
   
};

class Edge {
    Node start, end; 
    int rigid_index;

    public:

    Edge(const Node& a, const Node& b, int r_i){
        this->start = a;
        this->end = b;
        this->rigid_index = r_i;
    }
};

class DAG{
    int size;
    int edge_count;
    std::vector<Node> nodes;
    std::vector<Edge> edges;

    std::vector<std::vector<Node>> adj_lst;

    public:
    
    DAG();
    DAG(const std::vector<Node>& nodes, const std::vector<Edge>& edges);
    DAG(const DAG&);
    ~DAG();

    void construct_adjlist();
    void print();
};

// void print_graph(DAG const &graph, int N) {
//     for (int i=0; i<N; i++) {
//         std::cout << i << "--->";
//         for (Matrix v: graph.adj_lst[i]) {
//             std::cout << v << " ";
//         }
//         std::cout << '\n';
//     }
// }


DAG::DAG() {
    size = 0;
    edge_count = 0;
}

DAG::DAG(const std::vector<Node>& nodes, const std::vector<Edge>& edges){
    this->nodes = nodes;
    this->edges = edges;
    this->edge_count = this->edges.size();
    this->size = this->nodes.size();

}

void DAG::construct_adjlist(){

}

void DAG::print(){
    for (int i = 0; i < this->size; i++){
        print()
    }
}