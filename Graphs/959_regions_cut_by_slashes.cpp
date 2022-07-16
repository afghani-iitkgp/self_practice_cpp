#include <bits/stdc++.h>

using namespace std;


class DSU_Naive
{
    unordered_map<int, int> parent;
    public:
        void make_set(int v) 
        {
            parent[v] = v;
        }

        int find_set(int v)
        {
            if (parent[v]==v)
                return v;
            
            return find_set(parent[v]);
        }

        void union_set(int a, int b)
        {
            int x = parent[a];
            int y = parent[b];

            if (x!=y)
                parent[x]=y;
            
        }


};

bool find_cycle(int u, int v) 
{
    DSU_Naive ds;

    if (ds.find_set(u) == ds.find_set(v))
        return true;
    else 
        return false;            
}

int count_regions_by_slashes(vector<string> &grid)
{
    int n = grid.size();
    int count = 1;

    DSU_Naive dsu_obj;

    int i,j;

    for (i=0; i<((n+1)*(n+1)-1); i++)
        dsu_obj.make_set(i);

    for (i=0; i<=n; i++)
        dsu_obj.union_set(0, i);
    for (i=(n*(n+1)); i<=(n*(n+2)); i++)
        dsu_obj.union_set(0, i);
    for (i=1; i<n; i++) {
        dsu_obj.union_set(0, i*(n+1));
        dsu_obj.union_set(0, (i*(n+1)+n));
    }



    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char& ch = grid[i][j];
            int u, v;
            if (ch == '\\') {
                u = i*(n+1)+j;
                v = i*(n+1)+(n+1)+(j+1);
            } 
            else if (ch == '/') {
                u = i*(n+1)+j+1;
                v = i*(n+1)+(n+1)+j;
            }
            else 
                continue;

            if (find_cycle(u, v))
                count++;
            else 
                dsu_obj.union_set(u, v);

        }
    }

    return count;
    
}

int main()
{
    vector<string> grid = {"/\\", "\\/"};
    grid = {"/ \\/", " \\ \\", " // ", "\\/\\ "};


    int num = count_regions_by_slashes(grid);
    cout<<"\nNumber of regions = "<<num<<endl;

}