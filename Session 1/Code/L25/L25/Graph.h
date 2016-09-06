#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
class BaseGraph {
    protected:
        vector<list<pair<int, int> > > adjList;
        void addEdgeHelper(int src, int dest, int weight) {
            list<pair<int, int> >::iterator  it = adjList[src].begin();
            while (it != adjList[src].end()) {
                if ((*it).first == dest) {
                    (*it).second = weight;
                    return;
                }
                it++;
            }
            pair<int, int> P(dest, weight);
            adjList[src].push_front(P);
            return;
        }
        void DFSHelper(int src, vector<bool> & visited) {
            cout << src << " ";
            vector<int> adjvertices = adj(src);
            for (int i  =0 ;i < adjvertices.size(); i++) {
                if (!visited[adjvertices[i]]) {
                    visited[adjvertices[i]] = true;
                    DFSHelper(adjvertices[i], visited);
                }
            }
        }
    public:
        BaseGraph(int V) {
            adjList.resize(V);
        }
        vector<int> adj(int src) {
            vector<int> adjecentVertices;
            list<pair<int, int> >::iterator it = adjList[src].begin();
            while (it != adjList[src].end()) {
                adjecentVertices.push_back((*it).first);
                it++;
            }
            return adjecentVertices;
        }
        int numberofVertices() const {
            return adjList.size();
        }
        void BFS() {
            vector<bool> visited(adjList.size(), 0);
            for (int i = 0; i < visited.size();i++) {
                if (visited[i]) {
                    continue;
                }
                queue<int> Q;
                Q.push(i);
                visited[i] = true;
                while (!Q.empty()) {
                    int v =  Q.front();
                    Q.pop();
                    cout << v << " ";
                    vector<int> adjvertices = adj(v);
                    for (int j = 0; j < adjvertices.size(); j++) {
                        if (!visited[adjvertices[j]]) {
                            visited[adjvertices[j]] = true;
                            Q.push(adjvertices[j]);
                        }
                    }
                }
            }
        }
        bool isThereAPath(int src, int dest) const {
            vector<bool> visited(adjList.size(), 0);
            DFSHelper(src, visited);
            return visited[dest];
        }
        bool isBipartite() const {
            vector<int> vertexset(adjList.size(), 0);
            for (int i = 0; i < visited.size();i++) {
                if (vertexset[i] != 0 ) {
                    continue;
                }
                queue<int> Q;
                Q.push(i);
                vertexset[i] = 1;
                while (!Q.empty()) {
                    int v =  Q.front();
                    Q.pop();
                    vector<int> adjvertices = adj(v);
                    for (int j = 0; j < adjvertices.size(); j++) {
                        if (vertexset[adjvertices[j]] == vertexset[v]) {
                            return false;
                        } else if (vertexset[adjvertices[j]] == 0) {
                            vertexset[adjvertices[j]] = vertexset[v] == 1? 2 : 1;
                            Q.push(adjvertices[j]);

                        }
                    }
                }
            }
            return true;
        }
        void DFS() {
            vector<bool> visited(adjList.size(), 0);
            for (int i = 0; i < visited.size();i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    DFSHelper(i, visited);
                }
            }
        }
};
class UnWeightedUndirectedGraph : public BaseGraph {
    public:
        UnWeightedUndirectedGraph(int V) : BaseGraph(V) {}
        void addEdge(int src, int dest) {
            addEdgeHelper(src, dest, 0);
            addEdgeHelper(dest, src, 0);
        }

};
class UnWeightedDirectedGraph : public BaseGraph {
        bool isCyclicHelper(int v, vector<bool> &visited, vector<bool> &ances) {
            visited[v] = true;
            ances[v] = true;
            vector<int> adjvertices = adj(v);
            for (int i = 0; i < adjvertices.size(); i++) {
                if (ances[adjvertices[i]]) {
                    return true;
                }
                if (!visited[adjvertices[i]]) {
                    bool ans = isCyclicHelper(adjvertices[i], visited, ances);
                    if(ans) {
                        return true;
                    }
                }
            }
            ances[v] = false;
            return false;
        }
    public:
        UnWeightedDirectedGraph(int V) : BaseGraph(V) {}
        void addEdge(int src, int dest) {
            addEdgeHelper(src, dest, 0);
        }
        bool isCyclic() {
            vector<bool> visited(adjList.size(), 0);
            vector<bool> ances(adjList.size(), 0);
            for(int i = 0; i < visited.size(); i++) {
                if (visited[i] == false) {
                    bool ans = isCyclicHelper(i, visited, ances);
                    if (ans == true) {
                        return true;
                    }
                }
            }
            return false;
        }


}
#endif
