#include <iostream>
#include <fstream>

using namespace std;

int count(int A[], int l, int r);                     //r is the rightmost index
int countSplit(int A[], int l,int r);

int main(){
	int num;
	ifstream fin("IntegerArray.txt");
	while (fin >> num){
	
	}
}

int count(int A[], int l, int r){
	if (l == r){
		return 0;
	}
	else{
		int x,y,z;
		x = count(A[],l,r/2);
		y = count(A[],r/2+1,r);
		z = countSplit(A[], int l, int r);
		return (x+y+z);
	}
}

int countSplit(int A[], int l, int r){
	//FINISH THIS!!!
}
