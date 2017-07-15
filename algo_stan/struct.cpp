//=================================
// included dependencies
#include <iostream>
#include "struct.h"

//=================================
// stacks

Stack::Stack(){
    top = NULL;
}

void Stack::push(int num){
    Node *temp;
    temp = new Node;
    temp->val = num;
    temp->next = top;
    top = temp;
}

int Stack::pop(){
    if (top == NULL){
	return -1;		//Depends on the implementation
    }
    Node *temp;
    int num;
    temp = top;
    top = top->next;
    num = temp->val;
    delete (temp);
    return num;
}

void Stack::stackPrint(){
    Node *temp;
    temp = top;
    while (temp != NULL){
	std::cout << temp->val << " ";	//Needs iostream
	temp = temp->next;
    }
    std::cout << std::endl;
}

int Stack::status(){
    if (top == NULL){return -1;}
    else {return top->val;}
}


//=================================
// union-find

int find (struct subset set[], int i){			//Finds the root
    if (set[i].parent != i){
         set[i].parent = find(set,set[i].parent);	//Path compression
    }
    return set[i].parent;
}

void Union (struct subset set[], int x, int y){	//Does union by rank of x and y
    int rootx = find(set,x);
    int rooty = find(set,y);

    if (set[rootx].rank > set[rooty].rank){
        set[rooty].parent = rootx;
    }
    else if (set[rootx].rank < set[rooty].rank){
        set[rootx].parent = rooty;
    }
    else{
        set[rooty].parent = rootx;
        set[rootx].rank++;
    }
}

