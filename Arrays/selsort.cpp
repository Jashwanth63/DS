#include <iostream>
#include <climits>
using namespace std;


void selsort(int arr[], int n){
	for(int i=0; i<n-1; i++){
		int min = INT_MAX;
		int index;
		for(int j=i; j<n; j++)
			if(arr[j] < min){
				min = arr[j];
				index = j;
			}
		if(arr[i] > min){
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}

	
}

int main(){
	int arr[10];
	int i;
	int *sorted_array;
	for(i=0; i<10; i++){
		cin>>arr[i];
	}

	cout<<endl<<"Unsorted array: "<<endl;
	for(i=0; i<10; i++){
		cout<<arr[i];
	}
	selsort(arr, 10);
	cout<<endl<<"Sorted Array: "<<endl;
	for(i=0; i<10; i++){
		cout<<arr[i];
	}


	return 0;
}