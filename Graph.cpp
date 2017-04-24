#include <iostream>
#include <stack>
#include <queue>
#include "Graph.h"

using namespace std;

void Graph::addVertex(const std::string& node)
{
	if (!(adjacencyList.find(node) == adjacencyList.end()))
		{
		// if not found stop
		cout << node << " is a vertex in graph \n";
		return;
	}
	adjacencyList[node];
	
}

void Graph::addEdge(std::string sourceName, std::string targetName, int weight) throw(GraphException)
{try{
	if (adjacencyList.find(sourceName) == adjacencyList.end() || adjacencyList.find(targetName) == adjacencyList.end())
		throw;
}
	catch(GraphException a)
	{
		cout << "Node does not exist\n";
		return;
	}
	
	adjacencyList[sourceName][targetName] = weight;
	adjacencyList[targetName][sourceName] = weight;
}


void Graph::removeVertex(std::string nodeName) throw(GraphException)
{
	try{
		if (adjacencyList.find(nodeName) == adjacencyList.end() )
		throw;
		}
	catch (GraphException a)
	{
		cout << "Node does not exist\n";
		return;
	}

	adjacencyList.erase(nodeName);
	for(auto it:adjacencyList)
	{
		adjacencyList[it.first].erase(nodeName);
	}
}

void Graph::removeEdge(std::string srcName, std::string destName) throw(GraphException)
{
	try {
		if (adjacencyList.find(srcName) == adjacencyList.end()|| adjacencyList.find(destName) == adjacencyList.end())
			throw ;
	}
	catch (GraphException a)
	{
		cout << "Node does not exist\n";
		return;
	}
	adjacencyList[srcName].erase(destName);
	adjacencyList[destName].erase(srcName);
}

void Graph::DFS(const std::string& source)
{
	if (adjacencyList.find(source) == adjacencyList.end()) {
		// if not found stop
		cout << source << " not a vertex in graph \n";
		return;
	}
	// found
	

	vistedNodes[source] = true;//add node we are working on
	
	for (auto it:adjacencyList[source]) 
	{
		if (vistedNodes.find(it.first) == vistedNodes.end())//if not visited
		{
			
			cout << "("<<source<<", "<<it.first<<") ";
			DFS(it.first);
		}
		
	}
	cout << "<-";
	
}

void Graph::BFS(const std::string& source)
{
	if (adjacencyList.find(source) == adjacencyList.end()) {
		// not found
		cout << source << " not a vertex in graph \n";
		return;
	}

	/** Keeps track of explored vertices */
	map <string, bool> visted;
	queue<string> nodeList;

	/** Push initial vertex to the queue */
	nodeList.push(source);
	visted[source] = true; /** mark it as explored */
	cout << "Breadth first Search starting from vertex ";
	cout << source << " : " << endl;

	/** Unless the queue is empty */
	while (!nodeList.empty()) 
	{		
		/** Pop the vertex from the queue */
		string current = nodeList.front();
		nodeList.pop();

		/** From the explored vertex try to explore all the
		connected vertices */
		for (auto it : adjacencyList[current]) 
		{	
		
			if (visted.find(it.first) == visted.end()) //if not visited enqueue
			{
				cout << "( "<<current << ", "<<it.first<<" ) ";
				/** adds the vertex w to the queue */
				nodeList.push(it.first);
				/** marks the vertex w as visited */
				visted[it.first] = true;
			}
			
		}
	}
	cout << endl;
}

void Graph::shortestPath(const std::string& source)
{
	if (adjacencyList.find(source) == adjacencyList.end()) {
		// not found
		cout << source << " not a vertex in graph \n";
		return;
	}

	/* Keeps track of explored vertices */
	map <string, bool> visited;

	int minWeight = INT_MAX, total = 0;
	string minNode, curr = source;
	visited[source] = true; /** mark it as explored */
							/* Looping till priority queue becomes empty */
	stack<string> nodeList;

	/** Push initial vertex to the queue */
	nodeList.push(source);
	visited[source] = true; /** mark it as explored */
	cout << "Prims starting from vertex ";
	cout << source << " : " << endl;

	/** Unless the queue is empty */
	while (!nodeList.empty())
	{
		/** Pop the vertex from the queue */
		string current = nodeList.top();
		/** From the explored vertex try to explore all the
		connected vertices */
		for (auto it : adjacencyList[current])
		{

			if (visited.find(it.first) == visited.end() && minWeight > it.second)
			{// Updating key 
				minWeight = it.second;
				minNode = it.first;
			}

		}
		if (minWeight != INT_MAX)//if weight was changed
		{
			visited[minNode] = true;
			cout << "( " << current << ", " << minNode << " )\n";
			total += minWeight;
			nodeList.push(minNode);
			minWeight = INT_MAX;
		}
		else
		{
			nodeList.pop();
			minWeight = INT_MAX;
		}
	}
	cout << "\ntotal weight: " << total << endl;

}

void Graph::emptyVist()
{
	vistedNodes.clear();
	

}

std::ostream& operator<<(std::ostream& os, const Graph& temp)
{
	os << string(25, '*') << "Graph" << string(25, '*') << endl;
	os << "Vertices:\n";
	for (auto it : temp.adjacencyList)
	{
		os << it.first << "\t";
	}
	os << "\n\nEdges:\n";
	for (auto it : temp.adjacencyList)
	{
		for (auto x : it.second)
		{
			os << "( " << it.first << ", " << x.first << ", " << x.second << " )\t";
		}
	}

	return os;
}
