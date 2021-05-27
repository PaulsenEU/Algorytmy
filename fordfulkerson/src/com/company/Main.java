package com.company;

//package GraphTheory;
import java.util.Scanner;
public class FordFulkerson
{
    private static int traverse(int graph[][],int s,int t,int max_capacity,boolean visited[]){
        if(visited[s])
            return 0;
        if(s==t) {
            return max_capacity;
        }
        visited[s] = true;
        int ans = 0;
        for(int i=0;i<graph.length;i++){ if(graph[s][i]="">0){
            ans = traverse(graph,i,t,Math.min(max_capacity, graph[s][i]),visited);
            if(ans!=0){
                graph[s][i] = graph[s][i] - ans;
                graph[i][s] = graph[i][s] + ans;
                break;
            }
        }
        }
        return ans;
    }
    public static int fordFulkerson(int graph[][], int s, int t)
    {
        int flow = 0;
        while(true)
        {
            boolean visited[] = new boolean[graph.length];
            int ans = traverse(graph,s,t,Integer.MAX_VALUE,visited);
//If no more augmenting paths left
            if(ans==0) break;
            else
                flow += ans;
        }
        return flow;
    }
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
//Have to calculate the maximum flow from source to sink.
// int graph[][] =new int[][] { {0, 16, 13, 0, 0, 0},
// {0, 0, 10, 12, 0, 0},
// {0, 4, 0, 0, 14, 0},
// {0, 0, 9, 0, 0, 20},
// {0, 0, 0, 7, 0, 4},
// {0, 0, 0, 0, 0, 0}
// };
        int graph[][] = new int[][] { {0,3,3,2,0,0},
                {0,0,0,0,4,0},
                {0,0,0,1,0,2},
                {0,1,0,0,0,2},
                {0,0,0,1,0,1},
                {0,0,0,0,0,0}

        };
        int ans = fordFulkerson(graph,0,5);
        System.out.println("Maximum flow is: " + ans);
        s.close();
    }
}
