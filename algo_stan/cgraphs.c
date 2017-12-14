#include "cgraphs.h"


//  Definistions for Graph Representations

struct adjNode *newAdjNode(int dest){
    struct adjNode *newNode = (struct adjNode*)malloc(sizeof(struct adjNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct graph *createGraph(int V){
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    g->V = V;
    g->list = (struct adjList*)malloc(V*sizeof(struct adjNode));

    for (int i=0; i<V; i++)
        g->list[i].head = NULL;

    return g;        
}

void addEdge(struct graph *g, int src, int dest){
    struct adjNode *newNode = newAdjNode(dest);
    newNode->next = g->list[src].head;
    g->list[src].head = newNode;
}
