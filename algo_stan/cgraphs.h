#ifndef CGRAPHS_H_
#define CGRAPHS_H_

#include <stdlib.h>


//  Declarations for a Graph

struct adjNode{
    int dest;
    struct adjNode *next;
};

struct adjList{
    struct adjNode *head;
};

struct graph{
    int V;
    struct adjList *list;
};

struct adjNode *newAdjNode(int dest);
struct graph *createGraph(int V);
void addEdge(struct graph *g, int src, int dest);

#endif
