#include "dag.hpp"
#include <unordered_map> 
#include <chrono>
using namespace std;
using namespace std::chrono;
// namespace std{
//     template <>
//     struct hash<Node>
//     {
//         size_t operator() (const Node& node) const {
//             return ((hash<int>() (node.subprob.i) ^ hash<int>() (node.subprob.j) << 1) << 1);
//         }
//     };
// }

// namespace std{
//     template <>
//     struct hash<subproblem>
//     {
//         size_t operator() (const subproblem& subprob) const {
//             return ((hash<int>() (subprob.i) ^ hash<int>() (subprob.j) << 1) << 1);
//         }
//     };
// }

void DAGtest(int n){
    MatrixChain m1 = generate_chain(n);
    subproblem sub1 = subproblem(1, n, m1);
    DAG m_dag; 
    m_dag.create_edges(sub1);
    m_dag.create_adjlist();
    m_dag.print_adjlist();
}

void test(){
    int n = 1;
    bool ok = true;
    while(ok == true){
        
        auto start = high_resolution_clock::now();
        DAGtest(n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        
        if (duration.count()/1000000 < 120) {
        cout << "Time taken by function: "
         << duration.count()/1000000 << " seconds" << endl;
        n++;

        }
        else {
            cout << "Time taken by function: "  
            << duration.count()/1000000 << " seconds" << endl;
            ok = false;
        }
    }
}

int main() {  
    test();
    return 0;
}