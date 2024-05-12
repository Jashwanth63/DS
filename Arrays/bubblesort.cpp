#include <iostream>

using namespace std;


void bubblesort(int arr[], int n){
	for(int i=n-1; i>0; i--){
		for(int j=0; j<=i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}



int main()
{
	int arr[10];
	int i;
	i=10;
	for(int n=0; n<i; n++){
		cin>>arr[n];
	}
	bubblesort(arr, i);
	cout<<endl<<"Sorted array: "<<endl;
	for(int n = 0; n<i; n++){
		cout<<arr[n]<<" ";
	}

	return 0;
}