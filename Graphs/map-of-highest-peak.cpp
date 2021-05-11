#include <bits/stdc++.h>
using namespace std;


int** highestPeak(vector<vector<int>>& is_water) 
{
    int m = is_water.size();
    int n = is_water[0].size();
    
    int sizeY = 4;
    int sizeX =5;
    
    int **ary = new int*[sizeY];

    for(int i = 0; i < sizeY; ++i) {
        ary[i] = new int[sizeX];
    }


    int** A = new int*[m];

    for (int r=0; r<m; r++)
        A[r] = new int[n];

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (is_water[i][j] == 0)
                A[i][j] = 2;
            else if (is_water[i][j] == 1)
                A[i][j] = 0;
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (A[i][j] ==2 || A[i][j] == 1)
                continue;
            else if (A[i][j] == 0) {
                if (i>0) 
                    A[i-1][j] = 1;
                if (i<m)
                    A[i+1][j] = 1;
                if (j>0)
                    A[i][j-1] = 1;
                if (j<n)
                    A[i][j+1] = 1;

            }
        }
    }

    return A;

}


struct node 
{
    int i;
    int j;
    bool visited;
    int val;
};


vector<vector<int>> highest_peak2(vector<vector<int>> &is_water)
{   
    int nRow = is_water.size();
    int nCol = is_water[0].size();
    node* aux[nRow][nCol];

    queue<node*> q;

    

    for (int i=0; i < nRow; i++) {
        for (int j=0; j < nCol; j++) {
            node* u = new node;
            u->i = i;
            u->j = j;
            u->val = 0;
            u->visited = false;
            aux[i][j] = u;
 
            if (is_water[i][j] == 1) {
                u->visited = true;
                q.push(u);
            }        
        }
    }

    while (!q.empty()) {
        node* s = q.front();
        q.pop();

        if (s->visited == false || s->visited == true) {
            // s->visited = true;

            if (s->i > 0) {
                node* v = new node;

                v->i = s->i - 1;
                v->j = s->j;
                if (aux[v->i][v->j]->visited==false) {
                    v->val = s->val + 1;
                    // v->visited = true;
                    q.push(v);
                    aux[v->i][v->j] = v;
                    aux[v->i][v->j]->visited = true;
                }

                
            }

            if (s->i < nRow-1) {                 
                node* v = new node;

                v->i = s->i + 1;
                v->j = s->j;
                if (aux[v->i][v->j]->visited==false) {
                    v->val = s->val + 1;
                    v->visited = true;
                    q.push(v);
                    aux[v->i][v->j] = v;
                    aux[v->i][v->j]->visited = true;                    
                }


            }   

            if (s->j > 0) {
                node* v = new node;

                v->i = s->i;
                v->j = s->j - 1;
                if (aux[v->i][v->j]->visited==false) {
                    v->val = s->val + 1;
                    // v->visited = true;
                    q.push(v);
                    aux[v->i][v->j] = v;
                    aux[v->i][v->j]->visited = true;
                }
                

            } 

            if (s->j < nCol-1) {
                node* v = new node;

                v->i = s->i;
                v->j = s->j + 1;
                if (aux[v->i][v->j]->visited==false) {
                    v->val = s->val + 1;
                    // v->visited = true;
                    q.push(v);
                    aux[v->i][v->j] = v;
                    aux[v->i][v->j]->visited = true;
                }

            } 
        
        }
    }


    vector<vector<int>> vec;
    vec.resize(nRow);
    // for (int i=0; i<nRow; i++)
    //    vec[i].resize(nCol);

    for (int i=0; i<nRow; i++) {
        for (int j=0; j<nCol; j++) {
            cout<< aux[i][j]->val <<" -|- ";
            vec[i].push_back(aux[i][j]->val);
            // cout<< endl;
        }
        cout<< endl;
    }

    return vec;

}

int main()
{
    vector<vector<int>> is_water;
    is_water = { {0,0,1},{1,0,0},{0,0,0} };
    // is_water = { {0, 1} , {0, 0}};
    // is_water = {{0,1}, {0,1}};

    // int **A = highestPeak(is_water);

    // for (int i=0; i<is_water.size(); i++) {
    //     for (int j=0; j<is_water[0].size(); j++) {
    //         cout<< A[i][j] << " -- ";
    //     }
    //     cout<< endl;
    // }   


    // is_water =  {
    //                 {0,0,0,0,0,0,1,0},
    //                 {0,1,0,0,0,0,0,0},
    //                 {0,0,0,0,0,0,0,0},
    //                 {0,0,0,0,0,0,0,0},
    //                 {0,0,0,0,0,0,0,0},
    //                 {0,0,0,0,0,0,0,0},
    //                 {0,0,0,0,0,0,1,0},
    //                 {0,0,1,0,0,0,0,0}
    //             };

    is_water =  {
                    {0,0,0,0,0,0,1,0},
                    {0,1,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,1,0},
                    {0,0,1,0,0,0,0,0},                    
                    {0,0,0,0,1,0,0,0},                     
                    {1,0,0,0,0,0,0,0},                    
                    {0,0,1,0,0,0,1,1},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}
                                        
                };

    vector<vector<int>> v = highest_peak2(is_water);

    for (auto x=v.begin(); x != v.end(); x++) {
        for (auto y : *x)
            cout<< y << " | ";
        cout<<endl;
    }

    
    
    return 0;
}