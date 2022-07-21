#include <bits/stdc++.h>
using namespace std;

void dfs_recur(vector<vector<int>> &adjList, char *color, int u)
{
    color[u] = 'g';

    for (int i=0; i<adjList[u].size(); i++) {
        if (color[i]=='w') {
            dfs_recur(adjList, color, i);
        }
    }
    color[u] = 'b';
}


void dfs_main(vector<vector<int>> adjList)
{
    int V = adjList.size();
    char color[V]; 

    for(int i=0; i<V; i++) {
        color[i] = 'w';
    }

    for (int i=0; i<V; i++) {
        if (color[i]=='w') {
            dfs_recur(adjList, color, i);
        }
    }
}

int main() 
{

    vector<vector<int>> adjList = {{1,3}, {0,2,3}, {1,4}, {0,1}, {2}};

    dfs_main(adjList);

    return 0;
}