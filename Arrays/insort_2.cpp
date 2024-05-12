#include <iostream>

using namespace std;

void insort(int arr[], int n){
	for(int i=1; i<n; i++){
		int j = i-1;
		int element = arr[i];
		while(j>=0 && element<arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = element;
	}
}


int main(){
	int arr[10];
	int n=10;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	cout<<endl<<"Sorted Array: "<<endl;
	insort(arr, n);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}

	return 0;
	
} 