#include <iostream>
//#include <fstream>

using namespace std;

int sortCount(int A[], int temp[], int l, int r);                     	//r is the rightmost index
int mergeCount(int A[],int temp[], int l, int m,int r);

int sortCountStart(int A[], int array_size){				//To make array temp
    int *temp = new int[array_size];
    return sortCount(A, temp, 0, array_size-1);
}

int main(){
    int arr[5] = {1, 20, 6, 4, 5};
    cout << sortCountStart(arr,5) << endl;
    for (int i=0; i<5; i++)
	cout << arr[i] << " ";
    cout << endl;
}

int sortCount(int A[], int temp[], int l, int r){
    if (l == r){
        return 0;
    }
    else{
	int inv_count = 0;					//Don't forget about +=
	cout << inv_count;
	inv_count  = sortCount(A, temp, l, (l+r)/2);
	inv_count += sortCount(A, temp, (l+r)/2 + 1, r);		//Don't do r/2 like last time
	inv_count += mergeCount(A, temp, l, (l+r)/2, r);
	return inv_count;
    }
}

int mergeCount(int A[], int temp[], int l, int m, int r){	//To count split inversions
    int  i,j,k;
    int inv_count = 0;
    i = k = l;	//i - A and k - temp
    j = m;
    while (i < m && j <= r){
	if (A[i] <= A[j]){
	    temp[k++] = A[i++];
	}
	else{
	    temp[k++] = A[j++];
	    cout << "(" << A[i] << "," << A[j] << ")\n";
	    inv_count++;		//If the number after m is bigger it's an inversion
	}
    }
    while (i < m){
	temp[k++] = A[i++];
	inv_count++;			//All numbers left before m are added at the end and so are inversions
    }
    while (j <= r){
	temp[k++] = A[j++];
    }
    for (i=l; i <= r; i++)	//Copy back
        A[i] = temp[i];
    return inv_count;
}
