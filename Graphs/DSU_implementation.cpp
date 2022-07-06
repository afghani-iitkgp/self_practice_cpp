#include <bits/stdc++.h>
using namespace std;


class DisjointSet
{
    unordered_map<int, int> parent;
    public:
        void make_set(vector<int> const &universe)
        {
            for (int i: universe) {
                parent[i] = i;
            }
        }

        int find_set(int k)
        {
            if (parent[k] == k) {
                return k;
            }

            return find_set(parent[k]);
        }

        void union_set(int a, int b) 
        {
            int x = find_set(a);
            int y = find_set(b);

            if (x!=y) 
                parent[x]=y; 
        }
};

void print_sets(vector<int> const &universe, DisjointSet &dus_obj)
{
    for (int i: universe) {
        cout<< dus_obj.find_set(i)<<", ";
    }
    cout<<endl;
}

int main()
{
    vector<int> universe = {1,2,3,4,5,6,7};

    DisjointSet dsu_obj;
    dsu_obj.make_set(universe);
    print_sets(universe, dsu_obj);

    dsu_obj.union_set(4, 3);
    print_sets(universe, dsu_obj);

    dsu_obj.union_set(2, 1);
    print_sets(universe, dsu_obj);

    dsu_obj.union_set(6, 3);
    print_sets(universe, dsu_obj);

    dsu_obj.union_set(7, 2);
    print_sets(universe, dsu_obj);

}