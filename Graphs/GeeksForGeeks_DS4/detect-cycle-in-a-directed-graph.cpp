#include <bits/stdc++.h>
#include <string>
using namespace std;


// --------------- Function to detect cycle in a directed graph ------------------
string dfs_rec(vector<vector<int>> adj, int u, bool visited[], bool recStk[]) {
    visited[u] = true;
    recStk[u] = true;
    for (int v : adj[u]) {
        if (visited[v]==false) {
            dfs_rec(adj, v, visited, recStk);
        } 
        else {
            if (recStk[v]==true)
                return "YES";
        }
    }

    recStk[u] = false;
    return "No";
}



bool detect_cycle(vector<vector<int>> adj, int V) {
    bool visited[V], recStk[V];
    string s;
    for (int i=0; i<V; i++) {
        visited[i] = false;
        recStk[i] = false;
    }

    for (auto i=0; i<V; i++) {
        if (visited[i]==false) {
            s = dfs_rec(adj, i, visited, recStk);             
        }
        if (s.compare("YES")) {
            return true;
        }
        else 
            return false;
    }
}

int main() {
    vector<vector<int>> adj;

    adj = {{1}, {}, {1, 3}, {4}, {5}, {6}};
    int V = adj.size();

    bool s = detect_cycle(adj, V);
    cout<<s;

    return 0;
}