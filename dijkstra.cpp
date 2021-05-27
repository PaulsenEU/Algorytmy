#include <bits/stdc++.h>
using namespace std;
 
 
int get_min_index(int dist[], bool visited[], int n) {
    
    int min_dist = INT_MAX, min_index;

    for(int i = 0; i < n; i++) {
        if(!visited[i] && dist[i] <= min_dist)
            min_dist = dist[i], min_index = i;
    }

    return min_index;
}

void dijkstra(int **weights_matrix, int start, int n) {
    
    int dist[n];
    int pred[n];
    bool visited[n];
    
    for(int i = 0; i < n; i++)
        dist[i] = 9999, visited[i] = false, pred[i] = 0;

    dist[start] = 0;

    for(int i = 0; i < n - 1; i++) {

        int p = get_min_index(dist, visited, n); 
        visited[p] = true;

        for(int j = 0; j < n; j++) {
            if(!visited[j] && weights_matrix[p][j] && dist[p] != 9999 && dist[p] + weights_matrix[p][j] < dist[j]) {
                dist[j] = dist[p] + weights_matrix[p][j];
                pred[j] = p;
            }
        }
    }

    for(int i = 0; i < n; i++) 
        cout << dist[i] << ' ';

    cout << endl;

    for(int i = 0; i < n; i++)
        cout << pred[i] + 1 << ' ';
}

int main() {

    ifstream in;
    ofstream out;
    in.open("In0305.txt");
    int n, x, k;

    in >> n >> k;

    int **weights_matrix = new int* [n];
    
    for(int i = 0; i < n; i++ )
        weights_matrix[i] = new int [n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            in >> x;
            weights_matrix[i][j] = x;
        }

    dijkstra(weights_matrix, k - 1, n);

    in.close();
    out.close();
}