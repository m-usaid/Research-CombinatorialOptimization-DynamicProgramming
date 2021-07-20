#include "dag.hpp"
#include <unordered_map> 


namespace std{
    template <>
    struct hash<Node>
    {
        size_t operator() (const Node& node) const {
            return ((hash<int>() (node.subprob.i) ^ hash<int>() (node.subprob.j) << 1) << 1);
        }
    };
}

int main() {    
    MatrixChain m1 = generate_chain(5);
    subproblem sub1 = subproblem(1, 5, m1);
    subproblem sub2 = subproblem(1, 2, m1);
    subproblem sub3 = subproblem(1, 3, m1);
    subproblem sub4 = subproblem(1, 4, m1);
    // m.insert({{sub1, 5}});
    Node node1 = Node(sub1);
    Node node2 = Node(sub2);
    Node node3 = Node(sub3);
    Node node4 = Node(sub4);
    std::vector<Node> nbrs = {node2, node3, node4};
    std::unordered_map<Node, std::vector<Node>> m;
    m.insert({node1, nbrs});
    std::vector<Node> nbrs2 = {node1, node3, node4};
    m.insert({node2, nbrs2});
    for (auto &x: m) {
        std::cout << x.first << ": {";
        for (auto &y: x.second) {
            std::cout << y << " ";
        }
        std::cout << "}\n";
    }
    std::vector<Node> lst = m[node2];
    for (auto &i: lst) {
        std::cout << i;
    }
    
    return 0;
}