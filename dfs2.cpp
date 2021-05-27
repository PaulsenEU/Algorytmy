#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector <int> *adj;
    bool *visited;

    Graph(int V) {
        this->V = V;
        adj =  new vector <int> [V];
        visited = new bool [V];
        //cout << "visited: ";
        for(int i = 0; i < V; i++)
            visited[i] = false;
    }

    void addNode(int v, int w);
    void DFS(int v);
};

void Graph::addNode(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS(int v) {

    visited[v] = true;
    cout << v << endl;
    vector <int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i) {   
        if(visited[*i] == false) DFS(*i);
    }
}

int main() {

     Graph g(4);

    g.addNode(0, 1);
    g.addNode(0, 2);
    g.addNode(1, 2);
    g.addNode(2, 0);
    g.addNode(2, 3);
    g.addNode(3, 3);

    g.DFS(2);
}