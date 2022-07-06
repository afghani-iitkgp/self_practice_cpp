#include <bits/stdc++.h>
using namespace std;

struct re_type {
    bool v;
    set<int> s1;
    set<int> s2;
};

re_type bfs_check_bi_partition(vector<vector<int>> &graph) 
{
    int n = graph.size();
    queue<int> q;
    bool visited[n];
    fill(visited, visited + n, false);

    set<int> s1, s2;
    s1.insert(1);
    visited[1] = true;
    q.push(1);
    re_type x;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                q.push(v);

                if ( (s1.find(u) != s1.end()) && (s2.find(v) == s2.end()) ) {
                    s2.insert(v);
                }
                else if (s2.find(u) != s2.end() && (s1.find(v) == s1.end())) {
                    s1.insert(v);
                }
            }
            else if ( ( (s1.find(u) != s1.end()) && (s2.find(v) != s2.end()) ) || ( s2.find(u) != s2.end()) && s1.find(v) != s1.end() ) {
                continue;
            }
            else {
                x.v = false;
                x.s1 = s1;
                x.s2 = s2;
                return x;
            }
                
        }
    }

    x.v = true;
    x.s1 = s1;
    x.s2 = s2;


    return x;
}


bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n); // 0: uncolored; 1: color A; -1: color B
    
    queue<int> q; // queue, resusable for BFS    

    for (int i = 0; i < n; i++) {
        if (color[i])  // skip already colored nodes
            continue;
            
        // BFS with seed node i to color neighbors with opposite color
        color[i] = 1; // color seed i to be A (doesn't matter A or B) 
        for (q.push(i); !q.empty(); q.pop()) {
            int cur = q.front();
            for (int neighbor : graph[cur]) 
            {
                if (!color[neighbor]) // if uncolored, color with opposite color
                    { 
                        color[neighbor] = -color[cur]; 
                        q.push(neighbor); 
                    } 
                else if (color[neighbor] == color[cur]) 
                    return false; // if already colored with same color, can't be bipartite!
            }        
        }
    }

    return true;
}



bool isBipartite_v2(vector<vector<int>>& graph) {
    
    int N = graph.size();
    queue<int> q;
    bool visited[N];
    int set_val[N];

    for (int i=0; i<N; i++) {
        visited[i] = false;
        set_val[i] = 0;
    }


    q.push(0);
    set_val[0] = 1;
    visited[0] = true;

    while (! q.empty()) {
        int u = q.front();
        q.pop();

        // To check u is in which set.
        if (set_val[u] == 0) {
            set_val[u] = 1;
        }
        else 
            continue; 

        for (int v : graph[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                q.push(v);
                
                set_val[v] = (set_val[u] == 1) ? 2 : 1;
            }
            else if (set_val[v]==set_val[u])
                return false;
        }
    }

    return true;
}


int main ()
{
    vector<vector<int>> graph;
    graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    // graph = {{1,3},{0,2},{1,3},{0,2}};
    graph = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    // re_type is_bipartite = bfs_check_bi_partition(graph);
    // // cout<<"result = "<<is_bipartite<<"\n";

    // cout<<"result = "<<is_bipartite.v<<"\n";

    // for (auto i : is_bipartite.s2)
    //     cout<<i<<"; ";
    cout<<"\n"<<isBipartite(graph);

    cout<<"\n"<<isBipartite_v2(graph);

    cout<<endl;
}