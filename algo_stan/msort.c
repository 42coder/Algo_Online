#include <stdlib.h>
#include <stdio.h>

void sort(int arr[], int l, int r, int size);
void merge(int arr[], int l, int m, int r);		//r is the rightmost index

void print_arr(int arr[], int size){
    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);        
    }
    printf("\n");
}

int main(){
    int size;
    
    scanf("%d\n", &size);
    int num_array[size];
    for (int i=0; i<size; i++)  scanf("%d\n", &num_array[i]);

    sort(num_array, 0, size-1, size);
}

void sort(int arr[], int l, int r, int size){
    if (l != r){
        int m;
        m = l + (r-l)/2 ;
        sort(arr, l, m, size);
        sort(arr, m+1, r, size);
        merge(arr, l, m, r);
        //printf("%d %d\t", l, r);
        print_arr(arr, size);
	} 
}

void merge(int arr[], int l, int m, int r){
    int size = r-l+1;
    int temp[size];
    int i = l, j = m+1, k = 0;              // i starts from l and not 0

    while (i<=m && j<=r){
        //printf("\n%d %d %d \t", i, j, k);
        if (arr[i] < arr[j])    { temp[k] = arr[i]; i++; k++; }
        else    { temp[k] = arr[j]; j++; k++; }
    }    

    while (i<=m)    { temp[k] = arr[i]; i++; k++; }
    while (j<=r)    { temp[k] = arr[j]; j++; k++; }

    i = l; k = 0;
    while (k < size) { arr[i] = temp[k]; i++; k++; }
    //printf("\n");
}
