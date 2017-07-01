#include <iostream>
#include <vector>
#include "graphs.h"
#include "struct.h"

#define INT_MAX 90000

void printV(std::vector<int> path){
    for (std::vector<int>::const_iterator i = path.begin(); i != path.end(); ++i)
        std::cout << *i << ' ';
    std::cout << "\t" << path.size() << std::endl;
}



class dGraph : public Graph {
public:
    dGraph(int V):Graph(V){};
    void dks(int s);
};

void dGraph::dks(int s){
    std::vector<int> X;     //vertices so far
    X.push_back(s);         //include the source vertex

    int dist[V];    // The output array.  dist[i] will hold the shortest
                    // distance from src to i

    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[s] = 0;    //s-s dist = 0
    sptSet[s] = true;

    std::vector<int> temp;                      // have to declare it outside due to #2

    while (X.size() < V){
        std::vector<int>::iterator u;                   //those in X
        std::vector<std::pair<int, int> >::iterator j;  //those not in X
        int v,w;

        while (!temp.empty()){              // // // IMP ERROR
            if (!sptSet[temp.back()]){      // //Stupid ERROR - check if it already in it :P
                X.push_back(temp.back());           //1 - at pos #1 u for loop becomes INFINITE
                sptSet[temp.back()] = true;         //2 - at pos #2 the last iterations of the loop is skipped
            }
            temp.pop_back();
        }

        for (u=X.begin(); u<X.end(); u++){
            //printV(X);                                //debugging
            for (j = adj[*u].begin(); j!=adj[*u].end(); j++){
                v = j->first;                       //the vertex
                w = j->second;                      //edge weight
                //std::cout << "\t" << v << " " << w << "\n";   //debugging
                if(!sptSet[v] && dist[*u] + w < dist[v] ){
                    dist[v] = dist[*u] + w;
                }
                temp.push_back(v);          //Any problems with this?   #1
            }
        }                                   //                          #2
    }

    for (int i=0; i<V; i++){
        std::cout << "Node " << i << " distance = " << dist[i] << "\n";
    }
    std::cout << std::endl;
}

int main() {
    dGraph g(6);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    //g.addEdge(2, 4, 60);
    g.addEdge(4, 5, 50);
    g.addEdge(3, 5, 40);
    //g.addEdge(2, 5, 70);
    g.printGraph();
    g.dks(0);
    return 0;
}
