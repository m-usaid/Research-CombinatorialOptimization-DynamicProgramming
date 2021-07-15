#include <iostream>
#include <vector>
#include <matrix.hpp>

struct Edge {
    Matrix start, end; 
    int rigid_index;
};

class DAG{
    private:
    int size;
    int edge_count;

    public:
    std::vector<std::vector<Matrix>> adj_lst;
    
    DAG();
    
    DAG(std::vector<Edge> const &, int);
    DAG(DAG const &);
    ~DAG();

    void print();
};

void print_graph(DAG const &graph, int N) {
    for (int i=0; i<N; i++) {
        std::cout << i << "--->";
        for (Matrix v: graph.adj_lst[i]) {
            std::cout << v << " ";
        }
        std::cout << '\n';
    }
}

DAG::DAG() {
    size = 0;
    edge_count = 0;
}

DAG::DAG(std::vector<Edge> const &edges, int N){
    adj_lst.resize(N);
    size = N;
    edge_count = edges.size();
    for (auto &edge: edges){
        adj_lst[edge.start].push_back(edge.end);
    }
}

void DAG::print() {
    for (int i=0; i<size; i++) {
        std::cout << i << "--->";
        for (Matrix v: adj_lst[i]) {
            std::cout << v << " ";
        }
        std::cout << '\n';
    }
}

