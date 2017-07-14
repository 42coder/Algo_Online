#include <iostream>
#include <stdlib.h>
#include "graphs.h"
#include "struct.h"

using namespace std;

class mGraph: public Graph {
public:
	mGraph(int V):Graph(V){};
	int minCut();
};

int mGraph::minCut(){		//Using Karger's min-cut algo - a randomised algorithm

    struct subset *subsets = new subset[V];

    for (int i=0; i<V; i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int vertices = V;

    while (vertices > 2){
	int i = rand() % V;			//First point
	if (adj[i].size() == 0){
		continue;			//To avoid divide by zero error
	}
	std::vector<std::pair<int, int> >::iterator k;
	k = adj[i].begin() + rand() % adj[i].size();	//gotta think of some other way
	int j = k->first;			 //Second point

	int root1 = find(subsets, i);
        int root2 = find(subsets, j);

        if (root1 != root2){
	    //cout << "Contracting edge " << i << "-" << j << endl;
	    Union(subsets, root1, root2);
	    vertices--;
	}

	cout << "yo";
    }

    int cutedges = 0;
    for (int i=0; i<V; i++)				//To find minCut
    {
        int subset1 = find(subsets, i);
        std::vector<std::pair<int, int> >::iterator j;
	for (j = adj[i].begin(); j!=adj[i].end(); j++){
            int subset2 = find(subsets, j->first);
            if (subset1 != subset2)
                cutedges++;
	}
    }

    return cutedges/2;					//as to make an undirected graph I am using 2 directed edges
}

int main(){						// gfg example

    mGraph graph(25);
    graph.makeAdj();

    //graph.printGraph();

    // Use a different seed value for every run.
    srand(time(NULL));
    cout << "Cut found by Karger's randomized algo is " << graph.minCut() << endl;
    return 0;
}
