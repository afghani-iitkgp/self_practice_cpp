#include <bits/stdc++.h>
using namespace std;


void dfs_travel_recur(vector<vector<int>> &adjList, char *visited_color, int u)
{
    visited_color[u] = 'g';

    for (int v : adjList[u]) {
        if (visited_color[v]=='w') {
            dfs_travel_recur(adjList, visited_color, v);
        }
    }
    visited_color[u] = 'b';
}


int dfs_main(vector<vector<int>> &adjList, int N) 
{
    int cnt = 0;
    char visited_color[N];

    for (int i=0; i<N; i++)
        visited_color[i] = 'w';

    for (int i=0; i<N; i++) {
        if (visited_color[i] == 'w') {
                dfs_travel_recur(adjList, visited_color, i);
                cnt++;
        } 
    }


    return cnt;
}

int main()
{
    vector<vector<int>> graph;
    graph = {
                {1,1,0,0,0,0},
                {1,1,1,0,0,0},
                {0,1,1,0,0,0}, //3 -> 1, 2, 5
                {0,0,0,1,1,0},
                {0,0,0,1,1,0},
                {0,0,0,0,0,1}
        };

    graph = {{1,1,0},{1,1,0},{0,0,1}};
    graph = {{1,0,0}, {0,1,0}, {0,0,1}};

    // graph = {
    //     {1,1,0,1,0},
    //     {1,1,1,1,0},
    //     {0,1,1,0,1},
    //     {1,1,0,1,0}
    //     };

    // graph = {
    //     {1,1,0,1,0,0,0,0},
    //     {1,1,1,1,0,0,0,0},
    //     {0,1,1,0,1,0,0,0},
    //     {1,1,0,1,0,0,0,0},
    //     {1,1,0,1,0,0,0,0},
    //     {0,0,0,0,0,1,1,1},
    //     {0,0,0,0,0,1,1,1},
    //     {0,0,0,0,0,1,1,1},
    //     };


    int N = graph.size();
    vector<vector<int>> adjList(N);
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            //cout<<graph[i][j]<<", ";
            if (i!=j && graph[i][j]==1) {
                adjList[i].push_back(j);
            }
        }
    }


    // for (auto u : adjList) {
    //     for (int k=0; k<u.size(); k++) 
    //         cout<<u[k]<<"---";
    //     cout<<'\n';
    // }
    
    int cnt = dfs_main(adjList, N);
    cout<<"\nAns = "<<cnt<<'\n';
    return 0;
}