#include <bits/stdc++.h>
using namespace std;



void addEdge(vector<int> adjList[], int a, int b)
{
    adjList[a].push_back(b);
}

int findJudge (int V, vector<int> adjList[])
{
    for (int i; i<V; i++) {
        if (adjList[i].size() == 0)
            return i;
    }
    return -1;
}


int main()
{
    vector<vector<int>> trust;
    int V = 5;
    vector<int> adjList[V];

    trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};


    // for (auto it=trust.begin(); it!=trust.end(); it++)
    //     cout<<(*it)[0];
    // cout<<endl;
    // for (auto& it : trust)
    //     cout<<it[0];

    for (auto it=trust.begin(); it!=trust.end(); it++)
        addEdge(adjList, (*it)[0], (*it)[1]);


    // for (int i=0; i<V; i++) {
    //     for(auto& it : adjList[i])
    //         cout<<it<<"->";
    //     cout<<endl;
    // }

    //cout<<findJudge(V, adjList);


    // Creating frequency for all elements 
    unordered_map<int, vector<int>> umap;

    for (auto& it : trust) {
        umap[it[0]].push_back(it[1]); 
    }


    for(auto x : umap)
    {
        //cout<<x.first<<"  "<<x.second[1]<<endl;
        for (auto y : x.second)
            cout<<x.first<<" : "<<y<<" ";
        cout<<endl;
    }
    // for (auto x : umap) {
    //     for (auto y : x.first) {
    //         cout<<
    //     }
    // }

    int x;
    // Node* root;

    return 0;
}
