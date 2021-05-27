#include <bits/stdc++.h>
using namespace std;

class Graph {

private: 
    int V, E;
public:
    vector <pair <int, pair<int, int>>> edges;

    Graph(int V, int E) {
        this -> V = V;
        this -> E = E;
    }
     
    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}}); 
    }

    int kruskal();
};

class DisjSet {

    int *rank, *parent, n;

public:

    DisjSet(int n) {
        rank = new int[n + 1];
        parent = new int[n + 1];
        this -> n = n;

        for(int i = 1; i <= n; i++) {

            rank[i] = 0;
            parent[i] = i;
        }
    }

    //void makeSet();
    int find(int x);
    void Union(int x, int y);
};


/*void DisjSet::makeSet() {
    for(int i = 0; i < n; i++)
        parent[i] = i;
}*/

int DisjSet::find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void DisjSet::Union(int x, int y) {
    int xset = find(x);
    int yset = find(y);

    if(xset == yset) return;

    if(rank[xset] > rank[yset])
        parent[yset] = xset;
    else
        parent[xset] = yset;

    if(rank[xset] == rank[yset]) rank[y]++;
    
    
}

int Graph::kruskal() {

    int res = 0;

    sort(edges.begin(), edges.end());

    DisjSet ds(V);

    vector <pair <int, pair <int, int>>>::iterator it;

    for(it = edges.begin(); it != edges.end(); it++) {
        int u = it -> second.first;
        int v = it -> second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u != set_v) {
            res += it -> first;
            ds.Union(set_u, set_v);
            cout << u << ' ' << v << ' ' << it -> first << endl;
        }
    }

    return res;
}



int main() {
    

    ifstream we;
    ofstream wy;
    we.open("In0303.txt");
    wy.open("Out0303.txt");
    int n, m, v, w;
   

    we >> n >> m;

    string line;
    vector<string> tokens;
    Graph g(n, m);

    getline(we, line);
    for(int i = 1; i <= n; i++) {
        
        getline(we, line);
        istringstream iss(line);
        string token;
        while(getline(iss, token,' '))
            tokens.push_back(token);
        

        for(int j = 0; j < tokens.size(); j += 2) {
            g.addEdge(i, stoi(tokens[j]), stoi(tokens[j + 1]));
        }

        tokens.clear();
    }
    
    cout << endl;

    cout << g.kruskal();
    //g.kruskal();
    we.close();
    wy.close();
}
