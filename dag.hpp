#include <iostream>
#include "subproblem.hpp"
#include <unordered_map>

class Node {
    public: 
    subproblem subprob;
    int cost;
    Node() {}
    Node(const subproblem& s){
        this->subprob = s;
        this->cost = 0;
    };
    Node (const Node& other) {
        subprob = other.subprob;
        cost = other.cost;
    }
    ~Node() {}

    bool operator==(const Node& other) const {
        return (subprob == other.subprob);
    }

    friend std::ostream& operator<<(std::ostream& os, const Node& node);
};

class Edge {
    int rigid_index;

    public:
    Node start, end; 
    Edge() {}
    Edge(const Node& a, const Node& b) {
        start = a;
        end = b;
        rigid_index = 0;
    }
    Edge(const Node& a, const Node& b, int r_i){
        this->start = a;
        this->end = b;
        this->rigid_index = r_i;
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge);
};

std::ostream& operator<<(std::ostream& os, const Edge& edge) {
    os << "{" << edge.start << ", " << edge.end << "}";
    return os; 
}

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << "S(" << node.subprob.i << ", " << node.subprob.j << ")";
    return os;
}

namespace std{
    template <>
    struct hash<Node>
    {
        size_t operator() (const Node& node) const {
            return ((hash<int>() (node.subprob.i) ^ hash<int>() (node.subprob.j) << 1) << 1);
        }
    };
}

class DAG{
    int size;
    int edge_count;
    std::vector<Edge> edgelst;
    // std::unordered_map<Node, std::vector<Node>> adj_lst;
    std::unordered_map<Node, std::vector<Node>> adj_lst;

    public:
    DAG();
    DAG(const DAG&);

    // std::vector<Edge> DAG::create_edges(subproblem&);
    void create_edges(subproblem&);
    void print_edges() {
        std::cout << "Edges: {";
        for (auto &x: edgelst) {
            std::cout << x;
        }
        std::cout << "}\n";
    }

    void create_adjlist() {
        for (auto &edge: edgelst) {
            if (adj_lst.find(edge.start) == adj_lst.end()) {
                std::vector<Node> nbrs = {edge.end};
                adj_lst.insert({edge.start, nbrs});
            }
            else {
                adj_lst[edge.start].push_back(edge.end);
            }
        }
    }

    void print_adjlist() {
        std::cout << "Adjacency list of the DAG:\n";
        for (auto &x: adj_lst) {
            std::cout << x.first << " ---> ";
            for (auto &y: adj_lst[x.first]) {
                std::cout << y << " ";
            }
            std::cout << '\n';
        }
    }
    // void add_nodes(subproblem&);
    friend std::ostream& operator<<(std::ostream& os, const DAG& dag);
};


DAG::DAG() {

}

void DAG::create_edges(subproblem& subprob) {
    std::vector<subproblem> all_probs = subprob.get_all_subprob();
    for (auto &prob: all_probs) {
        for (auto &subprob: prob.subproblist) {
            edgelst.push_back(Edge(Node(prob), Node(subprob)));
        }
    }
}




// class DAG{
//     int size;
//     int edge_count;
//     std::vector<Node> nodes;
//     std::vector<Edge> edges;

//     std::vector<std::vector<Node>> adj_lst;

//     public:
    
//     DAG();
//     DAG(const std::vector<Node>& nodes, const std::vector<Edge>& edges);
//     DAG(const DAG&);
//     ~DAG();

//     void construct_adjlist();
//     void print();
// };

// // void print_graph(DAG const &graph, int N) {
// //     for (int i=0; i<N; i++) {
// //         std::cout << i << "--->";
// //         for (Matrix v: graph.adj_lst[i]) {
// //             std::cout << v << " ";
// //         }
// //         std::cout << '\n';
// //     }
// // }


// DAG::DAG() {
//     size = 0;
//     edge_count = 0;
// }

// DAG::DAG(const std::vector<Node>& nodes, const std::vector<Edge>& edges){
//     this->nodes = nodes;
//     this->edges = edges;
//     this->edge_count = this->edges.size();
//     this->size = this->nodes.size();

// }

// void DAG::construct_adjlist(){
    
// }

// void DAG::print(){
//     for (int i = 0; i < this->size; i++){
//         print()
//     }
// }