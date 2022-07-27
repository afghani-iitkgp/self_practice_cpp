#include <bits/stdc++.h>
#include <string>
using namespace std;


class Solution {
    public:
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


};


int main() {
    //cout<<"Enter number of test cases = ";
    //cin >> t;

    // while (t--) {
    //     int V, E;
    //     cout<<"\nNumber of vertices = ";
    //     cin>> V;
    //     cout<<"\nNumber of Edges = ";
    //     cin>> E;

    //     vector<int> adj[V];

    //     for (int i=0; i<E; i++) {
    //         int u, v;
    //         cin>>u>>v;
    //         adj[u].push_back(v);
    //     }

    //     Solution sol_obj;
    //     cout<< sol_obj.detect_cycle(adj, V)<<'\n';


    int V=6;
    cout<<"Enter number of vertices = \n";
    //cin >> V;

    vector<vector<int>> adj;

    adj = {{1}, {}, {1, 3}, {4}, {5}, {3}};

    Solution sol_obj;
    bool s = sol_obj.detect_cycle(adj, adj.size());
    cout<<s;

    return 0;
}