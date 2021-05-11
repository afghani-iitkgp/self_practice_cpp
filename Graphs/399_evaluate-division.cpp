#include <bits/stdc++.h>
using namespace std;


struct node {
    string i; 
    string j;
    double w;
};

double DFS_find(string src, string dest, unordered_map<string, bool> &visited, unordered_map<string, vector<pair<string, double>>> &mp) 
{
    for (auto u : mp[src]) {
        if (visited[u.first] == false) {
            visited[u.first] = true;

            if (u.first != dest) {
                double t = DFS_find(u.first, dest, visited, mp);

                if (t == -1.0)
                    return t;
                else 
                    return t * u.second;
            }

            else if (u.first == dest) {
                return u.second;
            }

        }
    }

    return -1.0;
         
}

vector<double> calc_equation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
{
    unordered_map<string, vector<pair<string, double>> > mp;
    unordered_map<string, bool> visited;
    unordered_set<string> string_set;
    int n = values.size();
    
    for (int i=0; i<n; i++) {
        string s1 = equations[i][0];
        string s2 = equations[i][1];
        double w = values[i];

        string_set.insert(s1);
        string_set.insert(s2);

        mp[s1].push_back(make_pair(s2, w));
        mp[s2].push_back(make_pair(s1, 1.0/w));
    }


    for (auto it : mp) {
        // cout<<it.first<<" : ";
        for (auto i : it.second)
            cout<<it.first<<" -> "<<i.first<< " : " <<i.second<<endl;
           
        // cout<<endl;
    }

    vector<double> vec;

    for (auto it : queries) {
        string src = it[0];
        string dest = it[1];
        double res;

        for (auto itr : string_set)
            visited[itr] = false;
        
        // if either of 'src' or 'dest' is not found
        if ( ( string_set.find(src) == string_set.end() ) || ( string_set.find(dest) == string_set.end() )  ) {
            res = -1.0;
        }
        // if both 'src' and 'dest' are found but they are same.
        else if (src == dest) {
            res = 1.0;
        }
        // if both 'src' and 'dest' are found and they aren't same.
        else {
            visited[src] = true;
            res = DFS_find(src, dest, visited, mp);
        }

        cout<<"\n"<<"result = "<<res<<"\n";
        vec.push_back(res);

    }


    return vec;
    
}


int main()
{
    /*
    Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
    Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
    Explanation: 
        Given: a / b = 2.0, b / c = 3.0
        queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
        return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
    */


    vector<vector<string>> equations;
    vector<double> values;
    vector<vector<string>> queries;

    equations = {
                {"a","b"},
                {"b","c"},
                };
    
    values = { 2.0, 3.0};
    queries = { 
                {"a","c"},
                {"b","a"},
                {"a","e"}, 
                {"a","a"}, 
                {"x","x"}
            };   

    
    vector<double> vec = calc_equation(equations, values, queries);

    for (auto it : vec) {
        cout<<it<<"  ";
    }


    return 0;
}