#include <iostream>
#include <vector>

using namespace std;

// data structure to store graph edges
struct Edge {
    int src, dest;
};

// Class to represent a graph object
class Graph 
{
public:
    // construct a vector of vectors to represent a adjacency list.
    vector<vector<int>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges, int N) 
    {
        //resize the vector to N elements of type vector<int>
        adjList.resize(N);

        //add edges to the directed graph
        for (Edge edge : edges) {
            // Insert at the end
            adjList[edge.src].push_back(edge.dest);

            // Uncomment below line for Undirected graph
            // adjList[edge.dest].push_back(edge.src);

        }

    }       
};


// Print adjacency list representation of graph
void printGraph(Graph graph, int N) 
{
    for (int i=0; i<N; i++) {
        // print current vertex number
        cout << i << "-->";

        // print all neighbouring vertices of vertex i
        for (int v : graph.adjList[i])
            cout<< v << " ";
        cout<< endl;
    }
}


int main()
{
    vector<Edge> edges = 
        {
            { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		    { 3, 2 }, { 4, 5 }, { 5, 4 }
        };

    // Number of nodes in the graph
    int N = 6;

    // construct graph
    Graph graph(edges, N);

    // print adjacency list representation of graph
    printGraph(graph, N);

    return 0;
}
