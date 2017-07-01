#include <iostream>
#include <fstream>
#include "graphs.h"				//Uses the old version of graphs needs new updates

using namespace std;

int minCut(struct Graph *graph){		//Using Karger's min-cut algo - a randomised algorithm
    int V = graph->V;
    int E = graph->E;
    Edge *edge = graph->edge;

    struct subset *subsets = new subset[V];

    for (int i=0; i<V; i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int vertices = V;

    while (vertices > 2){
	int i = rand() % E;

	int root1 = find(subsets, edge[i].src);
        int root2 = find(subsets, edge[i].dest);

        if (root1 != root2){
	    cout << "Contracting edge " << edge[i].src << "-" << edge[i].dest << endl;
	    Union(subsets, root1, root2);
	    vertices--;
	}
    }

    int cutedges = 0;
    for (int i=0; i<E; i++)				//To find minCut
    {
        int subset1 = find(subsets, edge[i].src);
        int subset2 = find(subsets, edge[i].dest);
        if (subset1 != subset2)
          cutedges++;
    }

    return cutedges;
}

/*int main(){						// gfg example
    /* Let us create following unweighted graph
        0------1
        | \    |
        |   \  |
        |     \|
        2------3
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;

    // Use a different seed value for every run.
    srand(time(NULL));

   cout << "\nCut found by Karger's randomized algo is " << minCut(graph) << endl;
   return 0;
}*/

int main(){
    ifstream fin("kargerMinCut.txt");
    //int V = 4, E = 10000, i = 0, node;		//Figure out a way to overcome this
    //struct Graph *graph = createGraph(V,E);

    std::string line;
    std::vector< std::vector<int> > all_integers;
    while ( getline( std::cin, line ) ) {
        std::istringstream is( line );
        all_integers.push_back(std::vector<int>( std::istream_iterator<int>(is), std::istream_iterator<int>() ) );
    }
    for(int n : v) {
        std::cout << n << '\n';
    }
    return 0;
}
