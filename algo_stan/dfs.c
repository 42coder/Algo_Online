#include <stdlib.h>
#include <stdio.h>

/*  The Graph structure
The Graph has an array of adjacency lists that point to the head of the linked list that stores the dest of each edges from a given vertex (that the head corresponds to)
The Graph also consists of the number of vertices and edges contatined within itself

Credits: GFG
*/

struct adjNode{
    int dest;
    struct adjNode *next;
};

struct adjList{
    struct adjNode *head;
};

struct graph{
    int V;
    struct adjList *array;
};

struct adjNode *newAdjNode(int dest){
    struct adjNode *newNode = (struct adjNode*)malloc(sizeof(struct adjNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void printGraph(struct graph *g){
    for (int v=0; v<g->V; v++){
        struct adjNode *pCrawl = g->array[v].head;
        printf("%d\n", v);
        while(pCrawl){
            printf("\t->%d\n", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
    }
}

struct graph *createGraph(int V);
void addEdge(struct graph *g, int src, int dest);
void dfs(struct graph *g);
void dfsUtil(struct graph *g, int covered[], int v);


int main(){
    int V, n, dest;

    /*  The Input File
    The first line contains the number of vertices
    The first letter of each line is the degree of the vertex followed by the dest vertices
    */
    scanf("%d\n", &V);
    struct graph *g = createGraph(V);
    for (int i=0; i<V; i++){
        scanf("%d", &n);
        for (int j=0; j<n; j++){
            scanf("%d", &dest);
            addEdge(g, i, dest);        //Be wary if the nodes start from 1 and not 0
        }
    }
    
    printGraph(g);
    dfs(g);    

    return 0;
}


struct graph *createGraph(int V){
    struct graph *g = (struct graph*)malloc(sizeof(struct graph));
    g->V = V;
    g->array = (struct adjList*)malloc(V*sizeof(struct graph));

    for (int i=0; i<V; i++)
        g->array[i].head = NULL;        

    return g;
}

//Edge nodes are added at the beginning of the ll (cause that's easier to handle)
void addEdge(struct graph *g, int src, int dest){
    //printf("%d %d\n", src, dest);
    struct adjNode *newNode = newAdjNode(dest);
    newNode->next = g->array[src].head;
    g->array[src].head = newNode;
}

void dfs(struct graph *g){
    int covered[g->V];
    for (int i=0; i<g->V; i++)
        covered[i] = 0;
    for (int i=0; i<g->V; i++){
        if (covered[i] == 0)
            dfsUtil(g, covered, i);
    }
    printf("\n");
}

void dfsUtil(struct graph *g, int covered[], int v){
    covered[v] = 1;
    printf("%d ", v);
    struct adjNode *pCrawl = g->array[v].head;
    while (pCrawl){
        if (covered[pCrawl->dest] == 0)
            dfsUtil(g, covered, pCrawl->dest);
        pCrawl = pCrawl->next;
    }
}

/*  Sample Test Case
11
2 1 2
3 0 3 4
2 0 5
3 1 6 7
2 1 8
3 2 9 10
1 3
1 3
1 4
1 5
1 5
*/
