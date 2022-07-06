#include <bits/stdc++.h>
using namespace std;


void dfs_recur(vector<vector<int>> &graph, vector<bool> &visited, int u) 
{
    
    for (auto v : graph[u]) {
        if (visited[v] == false) {
            visited[v] = true;
            dfs_recur(graph, visited, v);

        }
    }
} 


int dfs_main(vector<vector<int>> &graph, int n) 
{
    vector<bool> visited(n, false);
    // visited[0] = true;

    int cnt = 0;

    for (int i=0; i<n; i++) {
        if (visited[i] == false) {
            dfs_recur(graph, visited, i);
            cnt++;
        }
    }

    return cnt;

}

int main() 
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    int n = 5;

    edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    n = 5;

    edges = {
        {0, 1}, {0, 2}, {1, 2}, 
        {3, 4}, {3, 5}, {4, 5},
        {6, 7}, {6, 8}, {7, 9}, {8, 9},
        {10, 11}
    };

    n = 12;

    vector<vector<int>> graph;
    graph.resize(n);
    
    // create adjacency list for graph.
    for (auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    // for (auto i : graph) {
    //     for (int j : i) {
    //         cout<<j<<"  ";
    //     }
    //     cout<<endl;
    // }


    int cnt = dfs_main(graph, n);
    cout<<"count = "<<cnt<<'\n';


}
