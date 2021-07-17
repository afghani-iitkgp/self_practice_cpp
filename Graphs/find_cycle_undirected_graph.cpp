#include <bits/stdc++.h>
using namespace std;


bool dfs_backtracking(vector<int> adj[], int s, int p, bool visited[])
{
    for (int v : adj[s]) {
        if (visited[v] == false) {
            visited[v] = true;
            bool res = dfs_backtracking(adj, v, s, visited);
            
            if (res == true) // backtrack once cycle is found, otherwise run the loop for next vertices.
                return true;
        }

        else if ( (visited[v] == true) && (v != p) )
            return true;
    }

    return false;
}


bool detect_cycle_dfs(vector<int> adj[], int V)
{
    bool visited[V];
    bool t = false;

    for (int i=0; i<V; i++)
        visited[i] = false;
    
    for (int s=0; s<V; s++) {
        if (visited[s] == false) {
            visited[s] = true;
            t = dfs_backtracking(adj, s, -1, visited);
        }
    }

    return t;
}

void add_edge(vector<int>* adj, int u, int v)
{   
    // Adding edges to a Undirected graph
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int V = 6;
    vector<int> adj[V]; // Array of vectors.

    add_edge(adj, 0, 1);
    add_edge(adj, 2, 1);
	add_edge(adj, 2, 3); 
	add_edge(adj, 3, 4); 
	add_edge(adj, 4, 5);
	add_edge(adj, 5, 3);
    
    bool is_cycle = detect_cycle_dfs(adj, V);

    if (is_cycle == true)
        cout<<"Cycle found"<<'\n';
    else
        cout<<"No cycle is found"<<'\n';

    return 0;

}