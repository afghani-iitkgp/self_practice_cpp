#include <bits/stdc++.h>
using namespace std;

void DFS_travel(vector<int> adj[], int V, int s, int p, vector<bool>& visited)
{
    for (int i=0; i< V; i++) {
        if (visited[i]==false) {
            visited[i] = true;
            DFS_travel(adj, i, s, visited);
        }
    }
}

int main()
{   
    int V = 15;
    vector<vector<int>> edges;
    unordered_map<int, vector<int>> adjMapList;
    vector<int> adjArr[V];

    edges = { {1,2}, {1,6},
                {2,3}, {2,5},
                {3,4}, 
                {6,7}, {6,8}, {6,9},
                {7,13}, {7,14},
                {9,10}, {9,11}, {9,12},
                {14, 15},
                {11, 13}
             };


    // vector<bool> visited;
    // visited.assign(V, false);
    vector<bool> visited(V, false);

    
    for (auto e=edges.begin(); e!=edges.end(); e++) {
        int k = (*e)[0];
        int v = (*e)[1];
        adjMapList[k].push_back(v);
        adjMapList[v].push_back(k);
        
    }
    vector<vector<int>>::iterator it;
    for (auto it=edges.begin(); it!=edges.end(); it++) {
        adjArr[(*it)[0]-1].push_back((*it)[1]-1);
        adjArr[(*it)[1]-1].push_back((*it)[0]-1);
    }

    // // print_cycle_dfs(adjMapList, 1)
    // for (auto it : adjMapList) {
    //     cout << it.first <<"\n";
    //     for (int x : it.second) {
    //         cout<<x<<"--";
    //     }
    // }
    
    DFS_travel(adjArr, 0, -1, visited);

    
}