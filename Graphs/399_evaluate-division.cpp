#include <bits/stdc++.h>
using namespace std;


struct node {
    string i; 
    string j;
    double w;
};

vector<double> DFS_find(unordered_map<string, vector<pair<string, double>>> &mp) 
{
     
}

vector<double> calc_equation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
{
    unordered_map<string, vector<pair<string, double>> > mp;
    int n = values.size();
    
    for (int i=0; i<n; i++) {
        string s1 = equations[i][0];
        string s2 = equations[i][1];
        double w = values[i];

        mp[s1].push_back(make_pair(s2, w));
        mp[s2].push_back(make_pair(s1, 1.0/w));
    }


    for (auto it : mp) {
        // cout<<it.first<<" : ";
        for (auto i : it.second)
            cout<<it.first<<" -> "<<i.first<< " : " <<i.second<<endl;
            
        // cout<<endl;
    }
    

    vector<double> res = DFS_find(mp);

    
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
                {"b","c"}
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


    return 0;
}