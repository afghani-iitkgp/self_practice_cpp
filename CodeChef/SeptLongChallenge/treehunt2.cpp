#include <bits/stdc++.h>
using namespace std;


vector<pair<int, int>> findNeighbours(int i, int j, int d, int N, int M)
{
    vector<pair<int, int>> adjList;

    if (j-d >= 1)
        adjList.push_back({i, j-d});
    
    if (j+d <= M)
        adjList.push_back({i, j+d});

    if (i-d >= 1)
        adjList.push_back({i-d, j});

    if (i+d <= N)
        adjList.push_back({i+d, j});

    for (int k=1; k<d; k++) {

        if (i-k >= 1) {
            if (j+d-k <= M) 
                adjList.push_back( {i-k, j+d-k} );
            if (j-d+k >= 1) 
                adjList.push_back( {i-k, j-d+k} );
        }

        if (i+k <= N) {
            if (j+d-k <= M) 
                adjList.push_back( {i+k, j+d-k} );
            if (j-d+k >= 1) 
                adjList.push_back( {i+k, j-d+k} );
        }
    }

    return adjList;
}

int BFS_Traversal(pair<int, int> src_node, string **visited, int d, int N, int M)
{

    queue<pair<int, int>> q;
    q.push(src_node);
    visited[src_node.first - 1][src_node.second-1] = "gray";

    int cnt = 0;

    while (!q.empty()) {
        pair<int, int> curr_node = q.front();
        q.pop();
        visited[curr_node.first - 1][curr_node.second - 1] = "black";

        vector<pair<int, int>> adjNeighList = findNeighbours(curr_node.first, curr_node.second, d, N, M);

        for (auto itr : adjNeighList) {
            if (visited[itr.first - 1][itr.second - 1] != "black") {
                // cout<< curr_node.first << ", "<< curr_node.second << " ---->>> " << itr.first << ", "<< itr.second;
                cnt++;               
            }

            if (visited[itr.first - 1][itr.second - 1] == "white") {
                q.push(itr);
                visited[itr.first - 1][itr.second - 1] = "gray";
            }

            // cout<<"\n";
        }

    }

    return cnt;

}

int solve(int N, int M)
{
    int cvt = 0;


    string **visited;

    for (int d=1; d<=N+M-2; d++) {

        for (int i=0; i<N; i++) {
            visited[i] = new string[M];
            for (int j=0; j<M; j++) {
                visited[i][j] = "white";
            }
        }

        
        int A_k = 0;

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (visited[i][j] == "white") {
                    pair<int , int> src_node = {i+1, j+1};
                    A_k += BFS_Traversal(src_node, visited, d, N, M);
                }
            }
        }
        cout<<"A_k == "<<A_k<<" @d = "<<d<<"\n"; 

        cvt += A_k * pow(31, d-1);
    }


    // cvt = BFS_Traversal( {1, 1}, d);
    cout<<"cvt == >>>  " << cvt%998244353; 
    cout<<"\n"<< cvt;

    return cvt%998244353;
}


int main() {
    int T;
    int val;

    cout<<"Enter the value of T = \n";
    cin >> T;
    
    while (T--) {
        int N, M;
        cout<<"Enter the value of N = \n";
        cin>>N;

        cout<<"Enter the value of M = \n";
        cin>>M;
        
        val = solve(N, M);
        cout<<"\n\nValue ==>> "<< val;
        cout<<endl;
    }



    return 0;
}
