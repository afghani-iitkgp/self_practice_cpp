#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> graph = 
    graph = {
                {1,1,0,0,1},
                {1,1,0,0,1},
                {1,1,0,0,1},
                {1,1,0,0,1},
                {1,1,0,0,1},
                {1,1,0,0,1}
        };

    int n = graph.size();
    
    for (auto u : graph) {
        for (int i=0; i<n; i++) {
            cout<<u[i];
        }
    }

}