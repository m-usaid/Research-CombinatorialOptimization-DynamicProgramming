#include "dag.hpp"
#include <unordered_map> 

namespace std{
    template <>
    struct hash<subproblem>
    {
        size_t operator() (const subproblem& sub) const {
            return ((hash<int>() (sub.i) ^ hash<int>() (sub.j) << 1) << 1);
        }
    };
}

int main() {
    std::unordered_map<subproblem, int> m;
    MatrixChain m1 = generate_chain(5);
    subproblem sub1 = subproblem(1, 5, m1);
    m.insert({{sub1, 5}});
    for (auto &x: m) {
        std::cout << x.first << ", " << x.second;
    }
}