//=================================
// include guard
#ifndef __GRAPHS_H_INCLUDED__
#define __GRAPHS_H_INCLUDED__

//=================================
// included dependencies
#include <iostream>
#include <utility>
#include <vector>

#include <fstream>
#include <string>
#include <sstream>		//2 headers ust for taking inputs ????

//=================================
// directed graph using adjecency list

class Graph{
protected:
    int V,E;			               //Number of Vertices
    //std::vector<int> *adj;	 //The pointer to an array containing adjacency lists
    std::vector<std::pair<int, int> > *adj;  //To store weights also

public:
    Graph(int V);
    void addEdge(int v, int w, const int wt = 1);
    void printGraph();
    void makeAdj(const char* file = "test.txt");
};

#endif // __GRAPHS_H_INCLUDED__
