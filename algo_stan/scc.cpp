#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <time.h>
#include "struct.h"
#include "graphs.h"

using namespace std;

class scc : public Graph {
    int t; 				//finsihing times for 1st pass
    int S;				//current source vertex
    bool *visited;			//for dfs
    int *finTime;			//index is the finish time and the val is the node
    int *leader;
    vector<pair<int, int> > *trp;
public:
    scc(int V):Graph(V){
	trp = new vector<pair<int, int> >[V];
        visited = new bool(V);
	finTime = new int(V);
	leader = new int(V);
	S = -1;
	t = 0;
    };					//As we have inhereted the class Graph
    void dfsUtil(int v);
    void dfsSec(int v);
    void printScc();
    void addTrp(int u, int v, int wt = 1);
};

void scc::addTrp(int u, int v, int wt){
    trp[v].push_back(make_pair(u, wt));
}

void scc::printScc(){
    for (int i=0; i<V; i++){
	visited[i] = false;
    }
    for (int i = V-1; i >= 0; i++){				//Always go down
    	if (visited[i] == false){
	    dfsUtil(i);
	}
    }
    for (int i=0; i<V; i++){
	visited[i] = false;
    }
    for (int i = V-1; i >= 0; i++){
	int j = finTime[i];
	if (visited[j] == false){
	    S = j;
	    dfsSec(j);
	}
    }
    for (int i = 0; i < V; i++)
	cout << i << " " << finTime[i] << " " << leader[i] << endl;
}

void scc::dfsUtil(int v){					//Doing using stack as the file in the
    visited[v] = true;						//coursera course is huge and may exceed
    Stack stack;						//recursion limit
    stack.push(v);
    bool flag = false;
    //cout << v << " ";						//Better to write 2 code or a code to reverse graph?
    do{
	vector< pair<int,int> >::iterator i;
	for (i = trp[v].begin(); i < trp[v].end(); i++){
    	    if (visited[i->first] == false){
               	visited[i->first] = true;
               	stack.push(i->first);
		cout << i->first << " ";
		flag = true;
		break;
	    }
	}
	if (flag == false){
	    int j = stack.pop();
	    t++;
	    finTime[j] = t;
	}
        v = stack.status();
	flag = false;
    }while(v != -1);
}

void scc::dfsSec(int v){					//Doing using stack as the file in the
    visited[v] = true;						//coursera course is huge and may exceed
    Stack stack;						//recursion limit
    stack.push(v);
    bool flag = false;
    //cout << v << " ";						//Better to write 2 code or a code to reverse graph?
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
	    int j = stack.pop();
	    leader[j] = S;
	}
        v = stack.status();
	flag = false;
    }while(v != -1);
}


int main(){
    ifstream fin("test.txt");

    int a,b;
    fin >> a;			//Number of vertices
    scc g(a);

    while (fin >> a){		//Build graph
	fin >> b;
	g.addEdge(a,b);
        g.addTrp(a,b);
    }

    g.printScc();
    cout << endl;
    return 0;
}
