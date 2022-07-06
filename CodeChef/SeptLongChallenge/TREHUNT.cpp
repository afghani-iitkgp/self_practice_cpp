// https://www.codechef.com/SEPT21C/problems/TREHUNT

#include <bits/stdc++.h>
using namespace std;

// #define N 4 // Number of Rows
// #define M 5 // Number of Columns



int calculateSum(int N, int M, int K) 
{
    int cnt = 0;


    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            int  l = 0;
            if ( j+K <= M && i+K <= N ){                
                l = K+1;
                cnt += K+1;
            }
            else if ( j+K > M && i+K <= N ) {
                l = (K+1) - (j+K-M) > 0 ? (K+1) - (j+K-M) : 0; 
                cnt += l;
            }
            else if ( j+K <= M && i+K > N ) {
                l = (K+1) - (i+K-N) > 0 ? (K+1) - (i+K-N) : 0;
                cnt += l;
            }
            else if ( j+K > M && i+K > N ) {
                l = (K+1) - (i+K-N) - (j+K-M) > 0 ? (K+1) - (i+K-N) - (j+K-M) : 0;
                cnt += l;
               
            }
            
            cout<<"i = "<< i << " j = " << j << " l = " << l <<"\n";
        }
    }

    return cnt;
}

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
    // string visited[N][M];

    // for (int i=0; i<N; i++)
    //     for (int j=0; j<M; j++)
    //         visited[i][j] = "white";

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
    // int K;
    // cout<<"M = ";
    // cin>>M;
    // cout<<"N = ";
    // cin>>N;

    // K = 4;
    // int C = 0;
    // for (int t=1; t<=N+M-2; t++) {
    //     int A = calculateSum(N, M, t);
    //     cout<<"\n\n";
    //     A *= pow(31, t-1);
    //     C += A;
    // }

    // cout<<"\nCOUNT = " << C;
    // cout<<"\nModulo = " << C%998244353;

    // N = 9;  // #Rows
    // M = 8;  // #Columns
    // int d = 6; // Depth 
    // int x = 8; // x-coordinate
    // int y = 7; // y-coordinate.

    // int d = 2; // Depth 
    // int x = 1; // x-coordinate
    // int y = 1; // y-coordinate.

    // vector<pair<int, int>> adjList = findNeighbours(x, y, d);
    // int c = 0;

    // for (auto i : adjList) {
    //     cout<< i.first <<", " <<i.second;
    //     c += 1;
    //     cout<<"\n";
    // }
    // cout<<"c = "<< c;
    
    // for (int t=0; t<N+M-1; t++) {
    //     vector<pair<int, int>> adjList = findNeighbours(x, y, N, M, d);
    //     int c = 0;
    //     for (auto i : adjList) {
    //         cout<< i.first <<", " <<i.second;
    //         c += 1;
    //         cout<<"\n";
    //     }
    //     cout<<"c = "<< c;
    // }




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
        // cout<<"---------------------------------------\n";
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