#include <bits/stdc++.h>
using namespace std;
#define INF 9999

int min(int a, int b) {
    return (a<b)?a:b;
}

int cost[10][10], adj[10][10];

int main() {
   int vert, edge, i, j, k, c;
   cin >> vert;
   cin >> edge;

   for (k = 1; k <= edge; k++) { 
      cin >> i >> j >> c;
      adj[i][j] = cost[i][j] = c;
   }
   
   for (i = 1; i <= vert; i++)
      for (j = 1; j <= vert; j++) {
         if (adj[i][j] == 0 && i != j)
            adj[i][j] = INF; 
      }

   for (k = 1; k <= vert; k++)
      for (i = 1; i <= vert; i++)
         for (j = 1; j <= vert; j++)
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); 

   
   for (i = 1; i <= vert; i++) {
      for (j = 1; j <= vert; j++) {
            if (adj[i][j] != INF)
               cout << adj[i][j] << " ";
      }
      cout << "\n";
   }
}