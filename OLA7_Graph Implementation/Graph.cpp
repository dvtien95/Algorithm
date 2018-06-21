// Tien Dinh - CSCI3110-001 - ola7: Graph implementation

#include <iostream>
#include <stack>
#include <queue>
#include <set>

#include "Graph.h"

using namespace std;

// Add a vertex
// precond: node never appear in the graph before
void Graph::addVertex(string node)
{
	auto t = graph.find(node);
	if (t == graph.end())
		graph[node];
}

// Add an edge.
// Throw a GraphException if vertices of this
// node are not in this graph
// pre-cond: the edge between sourceName and targetName does not exist
void Graph::addEdge(string sourceName, string targetName, int weight)
        throw (GraphException)
{
	auto s = graph.find(sourceName);	// Find source vertex
	auto t = graph.find(targetName);	// Find target vertex
	if (t == graph.end() ||  s == graph.end())
		throw GraphException("Cannot find sourceNode or targetNode");
	else
	{
		graph[sourceName][targetName] = weight;	// Add edge btw source & target
		graph[targetName][sourceName] = weight;	// Add edge btw target & source
	}
}

// Remove a vertex and related arcs
// Throw a GraphException if such vertex does not exist
void Graph::removeVertex(string nodeName)
        throw(GraphException)
{
	auto t = graph.find(nodeName);
	if (t == graph.end())
		throw GraphException("Node does NOT exist to be deleted");
	else
		// Make a loop to traverse through all vertices that connected to the edgeToBeDeleted
		for (auto s = t->second.begin(); s != t->second.end(); ++s)
		{
			graph[s->first].erase(t->first);	// Erase the edge from other vertices first
		}
		graph.erase(t->first);	// Then erase the vertex itself
}

// Remove an edge 
// Throw a GraphException if both vertices are not in the graph
// Do nothing if the edge does not exist
void Graph::removeEdge(string srcName, string destName)
        throw(GraphException)
{
	auto s = graph.find(srcName);
	auto t = graph.find(destName);
	if (s == graph.end() && t == graph.end())
		throw GraphException("Both vertices are not in the graph");
	else if (s == graph.end() || t == graph.end())
		throw GraphException("One edge is missing, cannnot delete edge");
	else
	{
		graph[srcName].erase(destName);	// Delete edge connected to sourceVertex
		graph[destName].erase(srcName);	// Delete edge connected to targerVertex
	}
}

// Depth-first traversal: visit ALL vertices once
// During the visit, print edges in the order they are visited
// If graph has no edge, print some information
void Graph::DFS(string name)
{
	if (graph.empty())
		cout << "The graph has no edge" << endl;
	else
	{
		// Create a stack & visited node
		set<string> visited;
		stack<string> stack;
		
		// Mark current node as visted, push it in stack
		visited.insert(name);
		stack.push(name);
		
		while (!stack.empty())
		{
			// Pop an edge from stack and print it
			name = stack.top();
			cout << name << " ";
			stack.pop();
			
			// Get all adjacents edges to the popped one
			for(auto t = graph[name].begin(); t != graph[name].end(); ++t)
			{
				// If an adjacent edge is not visited, marked it as visited
				// then push it to the stack
				if (visited.find(t->first) == visited.end())
				{
					visited.insert(t->first);	// Mark is as visted by inserting to visited list
					stack.push(t->first);	// Push not visited one to the stack
				}
			}
		}	
		cout << endl;
	}
}

// Breadth-first traversal: visit ALL vertices once
// During the visit, print edges in the order they are visited
// If graph has no edge, print some information
void Graph::BFS(string name)
{
	if (graph.empty())
		cout << "The graph has no edge" << endl;
	else
	{
		// Create a queue & visited node
		set<string> visited;
		queue<string> queue;
		
		// Mark current node as visted, push it in queue
		visited.insert(name);
		queue.push(name);
		
		while (!queue.empty())
		{
			// Pop an edge from queue and print it
			name = queue.front();
			cout << name << " ";
			queue.pop();
			
			// Get all adjacents edges to the popped one
			for(auto t = graph[name].begin(); t != graph[name].end(); ++t)
			{
				// If an adjacent edge is not visited, marked it as visited
				// then push it to the queue
				if (visited.find(t->first) == visited.end())
				{
					visited.insert(t->first);	// Mark is as visted by inserting to visited list
					queue.push(t->first);	// Push not visited one to the queue
				}
			}
		}		
		cout << endl;
	}
}

// Find shortest path from the node "source"
void Graph::shortestPath(string name)
{
	cout << "Here is the shortest path: " << endl;
	
}

// print the graph
ostream& operator << (ostream& os, const Graph& g)
{
	os << endl << "Display the graph: " << endl;
	for(auto t = g.graph.begin(); t != g.graph.end(); ++t)
	{
		os << t->first << ": ";
		for (auto s = t->second.begin(); s!= t->second.end(); ++s)
			os << s->first << "-" << s->second << ",  ";
		os << endl;
	}
	return os;
}