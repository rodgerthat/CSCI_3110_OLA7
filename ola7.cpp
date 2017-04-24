/*
 * Author: Norris, Joel R.
 * Date: Apr 23, 2017
 * File: ola7.cpp
 * Description: Main program logic for ola7
 */

#pragma once
#include <iostream>
#include <string>
#include "Graph.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

void printMenu( void );				// display the main menu
void addVertex( void );				// add a vertex to the graph
void addEdge( void );				// add an edge to the graph
void removeVertex( void );			// remove a vertex from teh graph
void removeEdge( void );			// remove an edge from the graph
void DFS( void );					// perform Depth First Search
void BFS( void );					// perform Breadth First Search
void shortestPath( void );			// find the shortest path through the weighted graph
void printGraph( void );		// display the graph

Graph graph;

int main()
{

	// populate the graph
	graph.addVertex( "a" );
    graph.addVertex( "b" );
    graph.addVertex( "c" );
    graph.addVertex( "d" );
    graph.addVertex( "e" );
    graph.addVertex( "f" );
    graph.addVertex( "g" );
    graph.addVertex( "h" );
    graph.addVertex( "i" );

    graph.addEdge("a", "b", 6); 
    graph.addEdge("a", "f", 4); 
    graph.addEdge("a", "i", 2); 
    graph.addEdge("b", "c", 7); 
    graph.addEdge("b", "e", 9); 
    graph.addEdge("c", "d", 4); 
    graph.addEdge("c", "e", 3); 
    graph.addEdge("d", "g", 5); 
    graph.addEdge("d", "h", 1); 
    graph.addEdge("e", "g", 8); 
	graph.addEdge("f", "g", 2); 

	cout << graph;				// print out the graph
	cout << endl;
	cout << "Depth first Search starting from vertex a :";
	cout << endl;
	graph.DFS("a");				// perform Depth First Search on Graph
	cout << endl;
	graph.BFS("a");				// perform Breadth First Search on Graph
	cout << endl;
	graph.shortestPath("a");	// find the shortest path through the graph

	cout << "Press ENTER to continue";
	cin.get();

	// I really want to build a Menu class or something but the description says do it in the main function.
	while ( true ) 
	{
		// Display the main menu
		system("cls");		// clear the screen output buffer
		printMenu();		// display the main menu

		// get a menu command from the user
		char		command;
		cin >> command;
		cin.ignore(250, '\n');
		cout << endl;
        try {
		    switch ( command )
		    {
			    case '1': 	addVertex();
						    break;
                case '2':
                            removeVertex();
                            break;
                case '3':
                            addEdge();
                            break;
                case '4':
                            removeEdge();
                            break;
                case '5':
                            printGraph();
                            break;
                case '6':
                            DFS();
                            break;
                case '7':
                            BFS();
                            break;
                case '8':
                            shortestPath();
                            break;
			    case '9': 	
							return 0;  // terminate the loop
			    default:	
						    cout << "You input a wrong command!" << endl;	// user input error message
		    }
        } catch (GraphException e)
        {
            cout << e.what() << endl;
        }
		cout << "Press Enter to continue...";
		cin.ignore(200, '\n');
	}

    return 0;
}

// display the program menu
void printMenu( void ){
	cout
	<< "******************************************************" << endl
	<< "* Command   Description                              *" << endl
	<< "* 1         Add vertices                             *" << endl
	<< "* 2         Remove an vertex                         *" << endl
    << "*                                                    *" << endl
	<< "* 3         Add edges                                *" << endl 
	<< "* 4         Remove an edge                           *" << endl 
    << "*                                                    *" << endl
    << "* 5         Display the graph                        *" << endl
    << "*                                                    *" << endl
    << "* 6         Depth-first search spanning tree         *" << endl
    << "* 7         Breadth-first search spanning tree       *" << endl
    << "*                                                    *" << endl
    << "* 8         Find shortest path                       *" << endl
    << "*                                                    *" << endl
    << "* 9         Quit                                     *" << endl
	<< "******************************************************" << endl
	<< "Please enter your command [1-9]: ";
}

// read in user input nodes for the graph
void addVertex( void ) {

	string		name;

    cout << "Please enter node name (type q to quit): ";
    cin >> name;
    cin.ignore(200, '\n');

    while ( name != "q" )
    {
        graph.addVertex( name );
        cout << "Please enter node name (type q to quit): ";
        cin >> name;
        cin.ignore(200, '\n');
    }
	return;
}

// read in user input to remove certain nodes from teh graph
void removeVertex( void ) {
    string  name;

    cout << "Please enter node name: ";
    cin >> name;
    cin.ignore(200, '\n');

    graph.removeVertex( name );
	return;
}

// read in user input for edges to the weighted graph
void addEdge( void ) {
	string		src, dest;
    int         weight;

    cout << "Please enter edge info (src dest weight): ";
    cin >> src;
    cin >> dest;
    cin >> weight;
    cin.ignore(200, '\n');

	// allow user to terminate data input by entering a -1
    while ( weight != -1 )
    {
        graph.addEdge(src, dest, weight);
        cout << "Please enter edge info (src dest weight): ";
        cin >> src;
        cin >> dest;
        cin >> weight;
        cin.ignore(200, '\n');
    }
	return;
}

// read in user input to remove an arc from the graph
void removeEdge( void ) {
	string		src, dest;

    cout << "Please enter edge (src dest): ";
    cin >> src;
    cin >> dest;
    cin.ignore(200, '\n');

    graph.removeEdge(src, dest);
	return;
}

// display the current graph object contents
void printGraph( void ) {
    cout << graph << endl;
}

// get user input for a starting node to perform a Depth First Search on the graph
void DFS( void ) {
    string  name;
    cout << "Please enter starting vertex: ";
    cin >> name;
    cin.ignore(200, '\n');
    graph.DFS(name);
	graph.emptyVist();
}

// get user input for a starting node to perform a Breadth First Search on the graph
void BFS( void ) {
    string  name;
    cout << "Please enter starting vertex: ";
    cin >> name;
    cin.ignore(200, '\n');

    graph.BFS(name);
}

// get user input for a starting node to find the shortest path through the graph
void shortestPath( void ) {
    string  name;
    cout << "Please enter starting vertex: ";
    cin >> name;
    cin.ignore(200, '\n');
    graph.shortestPath(name);
}
