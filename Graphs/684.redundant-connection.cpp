#include <bits/stdc++.h>
using namespace std;


bool DFS(unordered_map<int, vector<int>> &m, int node, vector<int> visited, int parent ) 
{
    if (find(visited.begin(), visited.end(), node) != visited.end())
        return true;
    
    visited.push_back(node);

    for (int v: m[node]) {
        if (v==parent)
            continue;
        if (DFS(m, v, visited, node))
            return true;
    }

    return false;
}

vector<int> find_redundant_connection(vector<vector<int>> &Adj)
{
    int n = Adj.size();
    vector<int> visited;
    unordered_map<int, vector<int>> m;

    for (int i=0; i<n; i++) {
        int f = Adj[i][0];
        int s = Adj[i][1];

        m[f].push_back(s);
        m[s].push_back(f);

        if (DFS(m, f, visited, -1))
            return {f, s};
        
        visited.clear();
    }

    return {};

}



// DFS approach to find cycle in the graph.
bool has_cycle(int s, int e, int p, unordered_map<int, unordered_set<int>>& graph)
{
    bool x = graph[s].count(e);
    if (x == true)
        return true;
    
    for (int i : graph[s]) {
        if (i == p)
            continue;

        bool y = has_cycle(i, e, s, graph);
        if (y==true)
            return true;
    }
    
    return false;

}

bool has_cycle2(int s, int e, int p, unordered_map<int, unordered_set<int>>& graph)
{
    for (auto i : graph[s]) {
        
    }
}

vector<int> find_redundant_connection2(vector<vector<int>>& edges)
{
    unordered_map<int, unordered_set<int> > graph; // Adjacency list
    
    // Add each edge into the graph and check if there is a cycle.
    for (auto edge : edges) {
        bool t = has_cycle(edge[0], edge[1], -1, graph);
        if (t == true) {
            return edge;
        }

        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);

    }

    return {}; // No redundant edge found.
}

int main()
{
    vector<vector<int>> edges;
    edges = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};


    edges = {{1,5}, {2,6}, {3,8}, {4,9}, {4,10}, {5,8}, {6,8}, {7,9}, {8,10}, {9,10}}; 
    edges = {{9,10},{5,8},{2,6},{1,5},{3,8},{4,9},{8,10},{4,10},{6,8},{7,9}};


    vector<int> r = find_redundant_connection2(edges);

    for (int i: r)
        cout<<i<<'\n';
    cout<<'\n';
 

    return 0;
}