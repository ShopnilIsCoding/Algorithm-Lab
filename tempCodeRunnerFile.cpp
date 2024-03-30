#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int V) : V(V) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    int findParent(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = findParent(parent, parent[i]); 
    }

    void unionSets(vector<int>& parent, int x, int y) {
        int xset = findParent(parent, x);
        int yset = findParent(parent, y);
        if (xset != yset) {
            
            parent[xset] = yset;
        }
    }

    static bool compareEdges(const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    }

    void kruskalMST() {
        vector<int> parent(V, -1);
        vector<Edge> result;
        sort(edges.begin(), edges.end(), compareEdges);

        int e = 0, i = 0;
        while (e < V - 1 && i < edges.size()) {
            Edge nextEdge = edges[i++];
            int x = findParent(parent, nextEdge.src);
            int y = findParent(parent, nextEdge.dest);
            if (x != y) {
                result.push_back(nextEdge);
                unionSets(parent, x, y);
                e++;
            }
        }

        cout << "Edges in MST:" << endl;
        for (i = 0; i < result.size(); ++i)
            cout << result[i].src << " -- " << result[i].dest << "    Weight: " << result[i].weight << endl;
    }
};

int main() {
    int V = 4; 
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 3, 2);

    g.kruskalMST();

    return 0;
}
