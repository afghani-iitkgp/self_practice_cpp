#include <bits/stdc++.h>
using namespace std;

struct coord
{
    int x;
    int y;
};



vector<coord> findNeighbours(int N, coord Node)
{
     
    vector<coord> neighList;
    // int N = grid.size();

    int i = Node.x;
    int j = Node.y;

    if (i == 0 && j == 0) // Left-Upper most corner.
        neighList = { {i, j+1}, {i+1, j+1}, {i+1, j} };

    if (i == 0 && j == N-1) // Right-Upper most corner.
        neighList = { {i, j-1}, {i+1, j-1}, {i+1, j} };

    if (i == N-1 && j == 0) // Left-Bottom most corner.
        neighList = { {i-1, j}, {i-1, j+1}, {i, j+1} };

    if (i == N-1 && j == N-1) // Right-Bottom most corner.
        neighList = { {i-1, j}, {i-1, j-1}, {i, j-1} };


    if (i == 0 && j > 0 && j < N-1) // Horizontal-Upper arm.
        neighList = { {i, j-1}, {i+1, j-1}, {i+1, j}, {i+1, j+1}, {i, j+1} };

    if (i == N-1 && j > 0 && j < N-1) // Horizontal-Bottom arm.
        neighList = { {i, j-1}, {i-1, j-1}, {i-1, j}, {i-1, j+1}, {i, j+1} };


    if (i > 0 && i < N-1 && j == 0) // Vertical-Left arm.
        neighList = { {i-1, j}, {i-1, j+1}, {i, j+1}, {i+1, j+1}, {i+1, j} };

    if (i > 0 && i < N-1 && j == N-1) // Vertical-Right arm.
        neighList = { {i-1, j}, {i-1, j-1}, {i, j-1}, {i+1, j-1}, {i+1, j} };


    if (i > 0 && i < N-1 && j > 0 && j < N-1) // Nodes not lying on edges or corners.
        neighList = { {i-1, j}, {i-1, j+1}, {i, j+1}, {i+1, j+1}, {i+1, j}, {i+1, j-1}, {i, j-1}, {i-1, j-1} };


    return neighList;

}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
{
    int N = grid.size();
    
    bool visited[N][N];
    for (int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            visited[i][j] = false;


    queue<coord> Q;
    vector<coord> neighbourList;


    Q.push({0, 0});
    // coord* src_prev = new coord();
    // coord* src_curr = new coord();
    // coord src_prev = Q.front();
    
    
    vector<int> countLength;
    int cnt = 0;
    int curr_ele;

    while ( !Q.empty() ) {

        coord src_curr = Q.front();
        visited[src_curr.x][src_curr.y] = true;
        // Q.pop();
        neighbourList = findNeighbours(N, src_curr);
        
        for (coord itr : neighbourList) {
            if (visited[itr.x][itr.y] == false && grid[itr.x][itr.y] == 0)
                Q.push(itr);
            else
                continue;
        } 

        const coord src_prev = Q.front(); // Get current source vertex.
        Q.pop(); // Remove previous source vertex.

        // visited[src_curr.x][src_curr.y] = true;
        

        // for (coord C : neighbourList) {
        //     if (visited[C.x][C.y] ==  false && grid[C.x][C.y] == 0) {
                
        //         // visited[C.x][C.y] =  true;
        //         Q.push(C);
                
        //         cnt++;
        //     }
        //     else {
        //         continue;
        //     }
        // }

        // countLength.push_back(cnt);

    }

    int m = *max_element(countLength.begin(), countLength.end());
    return m;

}



int main()
{
    // int mat_size;
    // scanf("Enter the size of matrix = ", &mat_size);
    // // cin>>mat_size;

    vector<vector<int>> grid
    {
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };




    int res = shortestPathBinaryMatrix(grid);
    cout<<res<<"\n";

}