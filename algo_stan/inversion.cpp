//ERROR WHY YOU COMING!!!

#include <iostream>
//#include <fstream>

using namespace std;

//int sortCount(int A[], int temp[], int l, int r);                     	//r is the rightmost index
//int mergeCount(int A[],int temp[], int l, int m,int r);

/*int sortCountStart(int A[], int array_size)				//To make array temp
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
}*/

int mergeSort (int arr[], int l, int r);
void printArr (int arr[], int r);
int Merge (int arr[], int l, int m, int r);

int arr[]={1, 20, 6, 4, 5};
const int arr_size = sizeof(arr)/sizeof(arr[0]);

int main(){
    printArr(arr,arr_size);

    cout << "\n" << mergeSort(arr,0,arr_size-1) << "\n";

    printArr(arr,arr_size);

    cout << endl;

    return 0;
}

int mergeSort (int arr[], int l, int r){
    if (l < r){
        // Same as (l+r)/2, but avoids overflow for large array sizes
        int m = (r+l)/2;
     	int inv_count;

	inv_count = mergeSort(arr, l, m);
	inv_count += mergeSort(arr, m+1, r);
	inv_count += Merge(arr, l, m, r);

        printArr(arr,arr_size);
	cout << "\t" << inv_count << endl;
	return inv_count;
    }
}

int Merge(int arr[],int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int inv_count=0;

    int M[n1], N[n2];
    for (i = 0; i < n1; i++)
        M[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        N[j] = arr[m + 1+ j];

    i = 0; j = 0; k = l;
    while (i<n1 && j<n2){
        if (M[i] <= N[j]){
            arr[k] = M[i];
            i++;
            //cout << "yo1";
        }
        else{
            arr[k] = N[j];
	    cout << "\n(" << M[i] << "," << N[j] << ")";
            j++;
	    inv_count++;
            //cout << "lll";
        }
        k++;
    }
    cout << endl;
    while (i<n1){
        arr[k] = M[i];
	cout << M[i] << " ";
        i++; k++;
	inv_count++;
    }
    while (j<n1){
        arr[k] = N[j];
        j++; k++;
    }
    return inv_count;
}

void printArr(int arr[], int r){
    for (int i=0; i<r; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
