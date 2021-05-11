#include <bits/stdc++.h>
using namespace std;

void backtrack_dfs(vector<vector<int>> graph, int src, int dest,
                     vector<int> v, vector<vector<int>> *path)
{
    // Base condition:
    if (src == dest) {
        (*path).push_back(v);
        return;
    }

    for (int i=0; i<graph[src].size(); i++) {
        v.push_back(graph[src][i]);
        backtrack_dfs(graph, graph[src][i], dest, v, path);
        v.pop_back();
    }
    return;
}


vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int dest = graph.size() - 1;
    vector<int> v = {0};
    vector<vector<int>> path;
    backtrack_dfs(graph, 0, dest, v, &path);

    return path;
}


int main()
{
    vector<vector<int>> graph = { {1,3,4},
                                   {2,3,4},
                                   {3},
                                   {4},
                                   {} 
                                };

                                
    vector<vector<int>> ans; 
    ans = allPathsSourceTarget(graph);

    for (auto it=ans.begin(); it<ans.end(); it++) {
        for (int i : it[0]) 
            cout<< i<< ",";
        cout<<'\n';
    }

}