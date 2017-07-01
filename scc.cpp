#include <iostream>
#include <stdlib.h>
#include <list>             	//change list to vector
#include <time.h>
#include "struct.h"	 	//Use old ver
#include "graphs.h"		//Use old ver

using namespace std;

class scc : public Graph {
public:
    scc(int V):Graph(V){};			//As we have inhereted the class Graph
    void dfsUtil(int i, bool visit[]);
    void dfs();
};

void scc::dfs(){
    bool *visit = new bool(V);
    for (int i=0; i<V; i++){
	visit[i] = false;
    }
    for (int i=0;i<V; i++){
    	if (visit[i] == false){
	    dfsUtil(i,visit);
	}
    }
}

void scc::dfsUtil(int v, bool visited[]){
    visited[v] = true;
    Stack stack;
    stack.push(v);

    do{
	int v = stack.pop();
	cout << v << " ";
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
		stack.push(*i);
	    }
        }
    }while(stack.status());

/*// Mark the current node as visited and print it - gfg
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            dfsUtil(*i, visited);*/
}


int main(){
    scc g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    //g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 4);
    //g.addEdge(3, 3);
    cout << "Following is Depth First Traversal\n";
    g.dfs();
    return 0;
}
