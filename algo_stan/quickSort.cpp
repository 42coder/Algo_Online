#include <iostream>
#include <fstream>

using namespace std;

void quicksort(int arr[], int l, int r); 		//r is the rightmost index
int  partition(int arr[], int l, int r);		//pivot is the 1st element which is returned
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main(){

	int arr[10000], num;				//Try making it Dynamic - see containers
	int i = 0;
	ifstream fin("QuickSort.txt");
	while (fin >> num){
		//cout << num << endl; 			//For Testing
		arr[i++] = num;
	}

	//cout <<  partition(arr, 0, i-1) << endl;

	quicksort(arr, 0 ,i-1);

	for (int j=0; j<i; j++){
		cout << arr[j] << " ";
	}

	cout << endl;

	return 0;
}

void quicksort(int arr[], int l, int r){
	if (l < r){
		int p = partition(arr, l,  r);		//Nice step
		quicksort(arr, l, p-1);			//You forgot p-1 and p+1
		quicksort(arr, p+1, r);
	}
}

/*void quickSort(int arr[], int low, int high)		//gfg code
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}*/

int partition(int arr[], int l, int r){
	int p = arr[l];
	int i = l+1;					//Pivot position
	for (int j=l+1; j<=r; j++){
		if (arr[j] < p){
			int t;
			t = arr[j];
			arr[j] = arr[i];
			arr[i] = t;
			i++;
		}
	}
	int t;						//Make a swap function
	t =  arr[l];
	arr[l] = arr[i-1];				//Don't put 0 instead of l hear you studid idiot
	arr[i-1] = t;
	return (i-1);
}

/*int partition (int arr[], int low, int high)		//Courtesy GFG
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}*/
