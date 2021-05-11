/*
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]] 
*/

#include <bits/stdc++.h>

using namespace std;

void dfs_rec(vector<vector<int>> adj, bool visited[], int s);

// data structure to store DAG graph edges.
struct Edge {
    int src, dest;
};



void dfs_rec(vector<vector<int>> &adj, int s) 

{

    if (adj[s].size() == 0)
        return;

    cout<< s << "\n";


    for (int x : adj[s]) {
        dfs_rec(adj, x);
        // cout<<x<<"\n";
    }

}



vector<vector<int>> res; // global variable.


void DFS(vector<vector<int>> &graph, int node, vector<int> &path)
{
    if (node == graph.size()-1) {
        res.push_back(path);
        return;
    }


    // Consider every adjacent node of current node and do dfs to explore all possible paths

    for (int i=0; i<graph[node].size(); i++) {
        path.push_back(graph[node][i]); // add current adjacent node to path

        DFS(graph, graph[node][i], path);

        path.pop_back(); // remove current adjacent node from path
    }
}


vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<int> path;
    path.push_back(0);
    DFS(graph, 0, path); // DFS starting from src(node 0)

    return res;
}

int main()
{
    vector<vector<int>> lst;
    
    // lst =  { 
    //             {1, 3, 4}, // 0
    //             {2, 4},  // 1
    //             {3, 5, 6},  // 2
    //             {4}, // 3
    //             {},  // 4
    //             {}, // 5
    //             {5}  // 6
    //         };


    lst = {{ 4,3,1},{3,2,4},{3},{4},{}};
    
    vector<vector<int>> l = allPathsSourceTarget(lst);
    // cout<<l;


    return 0;
}
    





    

