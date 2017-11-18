// Tien Dinh - CSCI3110-001 - ola7: Graph implementation

#include <string>
#include <unordered_map>
#include <stdexcept>

using namespace std;

// Graph Exception
class GraphException : public logic_error
{
public:
    GraphException(string msg = "Graph Exception \n")
        : logic_error(msg.c_str())
    {}
};

//Undirtect connected graph
class Graph
{
public:
    // Add a vertex
    // precond: node never appear in the graph before
    void addVertex(string node );

    // Add an edge.
    // Throw a GraphException if vertices of this
    // node are not in this graph
    // pre-cond: the edge between sourceName and targetName does not exist
    void addEdge(string sourceName, string targetName, int weight )
        throw (GraphException);

    // Remove a vertex and related arcs
    // Throw a GraphException if such vertex does not exist
    void removeVertex(string nodeName )
        throw(GraphException);

    // Remove an edge 
    // Throw a GraphException if both vertices are not in the graph
    // Do nothing if the edge does not exist
    void removeEdge(string srcName, string destName )
        throw(GraphException);

    // Depth-first traversal: visit ALL vertices once
    // During the visit, print edges in the order they are visited
    // If graph has no edge, print some information
    void DFS(string name );

    // Breadth-first traversal: visit ALL vertices once
    // During the visit, print edges in the order they are visited
    // If graph has no edge, print some information
    void BFS(string name );

    // Find shortest path from the node "source"
    void shortestPath(string name );

    // print the graph
    friend ostream& operator << (ostream&, const Graph&);

private:
	unordered_map<string, unordered_map<string, int> > graph;
};

