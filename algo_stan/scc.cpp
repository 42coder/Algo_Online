#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <time.h>
#include "struct.h"
#include "graphs.h"

using namespace std;

class scc : public Graph {
    bool *visited;
public:
    scc(int V):Graph(V){
        visited = new bool(V);
    };					//As we have inhereted the class Graph
    void dfsUtil(int v);
    void dfs();
};

void scc::dfs(){
    for (int i=0; i<V; i++){
	visited[i] = false;
    }
    for (int i=0;i<V; i++){
    	if (visited[i] == false){
	    dfsUtil(i);
	}
    }
}

void scc::dfsUtil(int v){
    visited[v] = true;
    Stack stack;
    stack.push(v);
    bool flag = false;
    cout << v << " ";
    do{
	vector< pair<int,int> >::iterator i;
	for (i = adj[v].begin(); i < adj[v].end(); i++){
	    if (visited[i->first] == false){
                visited[i->first] = true;
                stack.push(i->first);
		cout << i->first << " ";
		flag = true;
		break;
	    }
	}
	if (flag == false){
	    stack.pop();
	}
        v = stack.status();
	flag = false;
    }while(v != -1);

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
    ifstream fin("test.txt");

    int a,b;
    fin >> a;			//Number of vertices
    scc g(a);

    while (fin >> a){		//Build graph
	fin >> b;
	g.addEdge(a,b);
    }

    cout << "Following is Depth First Traversal\n";
    g.dfs();
    cout << endl;
    return 0;
}
