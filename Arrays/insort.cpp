#include <iostream>

using namespace std;

void insort(int arr[], int n){
	for(int i = 1; i<n; i++){
		//j = i-1;
		int index = i;
		for(int j=i-1; j>=0; j--){
			if(arr[i] < arr[j]){
				index = j;
			}
			else{
				break;
			}
		}
		//int number = arr[i];
		for(int j=i;j>index;j--){
			swap(arr[j-1], arr[j]);
		}
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