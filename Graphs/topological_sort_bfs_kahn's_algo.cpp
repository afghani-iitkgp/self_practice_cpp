#include <bits/stdc++.h>
using namespace std;

vector<int> topological_sorting_bfs(vector<int> adj[], int V) 
{
    vector<int> in_degree(V, 0);

    vector<int> topological_sorted_list;

    for (int u=0; u<V; u++) {           // To create 'in_degree' array.
        for (auto x : adj[u]) 
            in_degree[x]++;
    }

    queue<int> q;

    for (int i=0; i<V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        cout<<u<<"\n";
        
        topological_sorted_list.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                q.push(v);
        }
    }

    return topological_sorted_list;
}


int main()
{
    int V = 5;
    vector<vector<int>> graph = { {0, 2}, {0, 3}, {1, 3}, {1, 4}, {2, 3} };

    vector<int> adj[V];

    for (vector<vector<int>>::iterator i= graph.begin(); i != graph.end(); i++) {

        // cout<< (*i)[0];
        adj[(*i)[0]].push_back((*i)[1]);
    }

    cout << "Following is a Topological Sort of\n"; 

    vector<int> list = topological_sorting_bfs(adj, V);

    for (auto it : list) 
        cout<< it << "--";

}
