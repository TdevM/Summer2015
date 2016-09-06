#include<iostream>
#include"Graph.h"
using namespace std;
int main() {
    UnWeightedUndirectedGraph G(7);
    G.addEdge(0, 3);
    G.addEdge(0, 1);
    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(3, 1);
    G.addEdge(4, 5);
    G.addEdge(5, 6);
    G.addEdge(6, 4);

    G.BFS();
    cout << endl;
    G.DFS();
    return 0;
}
