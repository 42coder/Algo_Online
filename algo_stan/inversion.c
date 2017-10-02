#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sortCount(int arr[], int l, int r);
int countSplit(int arr[], int l, int m, int r);

void print_arr(int arr[], int size){
	for (int i = 0; i < size; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main(){
	int n,i;

        scanf("%d\n", &n);
        printf("\nThe number of line in the input file, n = %d", n);

	const int size = n;
	int arr[size];
        for (i=0; i<size; i++){
		scanf("%d\n", &n);
		arr[i] = n;
        }
	printf("\nThe input array: ");
	for (i=0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\nThe number of inversions = %d\n", sortCount(arr,0,size-1));
	return 0;
}

int sortCount(int arr[], int l, int r){	//r is rightmost index
	if (l < r){
		int m = l+(r-l)/2;	//Avoids overflow for large l and r
		int sum = 0;

		sum = sortCount(arr,l,m);
		sum += sortCount(arr,m+1,r);	//m+1 is important
		sum += countSplit(arr,l,m,r);

		return sum;
	}
	else{
		return 0;
	}
}

int countSplit(int arr[], int l, int m, int r){
	int n1 = m-l+1, n2 = r-m;	//Needed for code readability
	int L[n1], R[n2];		//temp left and right subparts of the array
	int i, j, k;			//pointer to the array
	int inv = 0;

	for (i = 0; i <= n1; i++)
		L[i] = arr[l+i];
	for (j = 0; j <= n2; j++)
		R[j] = arr[m+1+j];

	i = j = 0;
	k = l;

	while (i < n1 && j < n2){
		if (L[i] > R[j]){
			arr[k++] = R[j++];
			inv += n1-i;			//If an element in the second half is bigger
		}					//then no of inv = no of elements left in
		else					//second array
			arr[k++] = L[i++];
	}
	while (i < n1){
		arr[k++] = L[i++];
	}
	while (j < n2){
		arr[k++] = R[j++];
	}
	return inv;
}
