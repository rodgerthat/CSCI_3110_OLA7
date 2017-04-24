#pragma once

#include <string>
#include <vector>
#include <list>
#include <map>


class GraphException : public std::exception
{
public:
    GraphException(std::string msg = "Graph Exception")
        : exception(msg.c_str())
    {}
};


//Undirtect connected graph
class Graph
{
public:
	
    // Add a vertex
    // precond: node never appear in the graph before
    void addVertex( const std::string& node );

    // Add an edge.
    // Throw a GraphException if vertices of this
    // node are not in this graph
    // pre-cond: the edge between sourceName and targetName does not exist
    void addEdge( std::string sourceName, std::string targetName, int weight )
        throw (GraphException);

    // Remove a vertex and related arcs
    // Throw a GraphException if such vertex does not exist
    void removeVertex( std::string nodeName )
        throw(GraphException);

    // Remove an edge 
    // Throw a GraphException if both vertices are not in the graph
    // Do nothing if the edge does not exist
    void removeEdge( std::string srcName, std::string destName )
        throw(GraphException);

    // Depth-first traversal: visit ALL vertices once
    // During the visit, print edges in the order they are visited
    // If graph has no edge, print some information
    void DFS( const std::string& source );

    // Breadth-first traversal: visit ALL vertices once
    // During the visit, print edges in the order they are visited
    // If graph has no edge, print some information
    void BFS( const std::string& source );

    // Find shortest path from the node "source"
    void shortestPath( const std::string& source );

    // print the graph
    friend std::ostream& operator << (std::ostream&, const Graph&);
	void emptyVist();
    /////////////////////////////////////////////////////////////
    // Add member functions and data here
    // You can use either adjacency list or adjacency matrix
    /////////////////////////////////////////////////////////////
	
private:
	std::map<std::string, std::map<std::string, int> > adjacencyList;
	std::map<std::string, bool> vistedNodes;
	int numNodes = 0;
};
