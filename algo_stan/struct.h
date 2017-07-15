//=================================
// include guard
#ifndef __STRUCT_H_INCLUDED__
#define __STRUCT_H_INCLUDED__

//=================================
// included dependencies
#include <iostream>

//=================================
// stacks

struct Node{
    int val;
    struct Node *next;
};

class Stack{
    Node *top;
public:
    Stack();
    void push(int num);
    int pop();
    int status();
    void stackPrint();
};

//=================================
// union

struct subset{			//union-find implementation
    int parent;
    int rank;
};

int find (struct subset set[], int i);			//Finds the root
void Union (struct subset set[], int x, int y);		//Does union by rank of x and y


#endif // __STRUCT_H_INCLUDED__
