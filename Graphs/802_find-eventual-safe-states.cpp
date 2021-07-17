#include <bits/stdc++.h>
using namespace std;

unordered_set<int> cycle_nodes;
unordered_set<int> safe_nodes;


bool DFS_Rec(vector<vector<int>>& graph, int i, unordered_set<int> visited_nodes)
{
    if (safe_nodes.find(i) != safe_nodes.end())
        return true;
    
    if (cycle_nodes.find(i) != cycle_nodes.end())
        return false;
    
    if (visited_nodes.find(i) != visited_nodes.end() ) {
        cycle_nodes.insert(i);
        return false;
    }

    visited_nodes.insert(i);

    for (int v : graph[i]) {
        bool l = DFS_Rec(graph, v, visited_nodes);

        if (l == false) {
            cycle_nodes.insert(v);
            return false;
        }
    }

    safe_nodes.insert(i);
    
    return true;
}



bool dfs (const vector<vector<int>>& g, int i, unordered_set<int> visited_nodes) 
{    
	if (safe_nodes.find (i)  != safe_nodes.end ())                // we know safe already
        return true;
	if (cycle_nodes.find (i) != cycle_nodes.end ())               // we know in cycle already
        return false;
        
	if (visited_nodes.find (i) != visited_nodes.end ()) {         // we have determined node is in cycle
		cycle_nodes.insert (i);
		return false;
	}

	visited_nodes.insert (i);                                     // keep track of nodes we've visited already

	for (int node : g[i]) {

        bool t = dfs(g, node, visited_nodes);

		if (t == false) {
			cycle_nodes.insert (i);                               // if child is in cycle, parent must be too
			return false;
		}
	}

	safe_nodes.insert (i);                                       // we know node is safe now
        
	return true;
}

    
vector<int> eventual_safe_nodes(vector<vector<int>>& graph)
{
    vector<int> ans;
    unordered_set<int> visited_nodes;

    for (int i=0; i < graph.size(); i++) {
        // bool t = DFS_Rec(graph, i, visited_nodes);
        bool t = dfs(graph, i, visited_nodes);

        if (t==true) {
            ans.push_back(i);
        }
    }

    return ans;
}




int main()
{
    vector<vector<int>> graph;
    graph = { {1, 2}, {2, 3}, {5}, {0}, {5}, {}, {} };

    vector<int> ans = eventual_safe_nodes(graph);

    for (int i=0; i<ans.size(); i++)
        cout<<ans[i]<<"  ";
    
    cout<<'\n';

}