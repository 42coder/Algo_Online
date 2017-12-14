//=================================
// included dependencies
#include <iostream>
#include "graphs.h"
#include <utility>
#include <vector>				//Do we have to include it here also
                                //Would a list have been a better option ?

//=================================
// directed graph using adjacency list representation

Graph::Graph(int V)
{
    this->V = V;
    adj = new std::vector<std::pair<int, int> >[V];
}

void Graph::addEdge(int v, int u, const int wt)
{                                               // // // Check if the edge is already there ?
    //adj[u].push_back(std::make_pair(v, wt));
    adj[v].push_back(std::make_pair(u, wt));   //For undirected graphs
    E++;
}

void Graph::printGraph(){
    int v, w;
    std::vector<std::pair<int, int> >::iterator it;
    for (int u = 0; u < V; u++){
        std::cout << "Node " << u << " makes an edge with \n";
        for (it = adj[u].begin(); it!=adj[u].end(); it++){
            v = it->first;
            w = it->second;
            std::cout << "\tNode " << v << " with edge weight = "
                 << w << "\n";
        }
        std::cout << "\n";
    }
}

void Graph::makeAdj(const char* file){			//May be broken
	std::ifstream fin(file);

	std::string line;
	int num,V;

	while (getline(fin, line)){
		std::istringstream is(line);
		is >> V;		
		while (is >> num){
			adj[V-1].push_back(std::make_pair(num, 1));
		}
	}
}
