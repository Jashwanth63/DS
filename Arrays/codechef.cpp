#include <iostream>
using namespace std;

void merge(int *arr, int s, int e){
	int mid = (s+e)/2;
	int i=s;
	int j=mid+1;
	int temp[100] = {0};
	int k=s;

	while(i<=mid and j<=e){
		if(arr[i]<arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=e){
		temp[k++] = arr[j++];
	}
	//cout<<k<<" ";
	//cout<<e<<" ";
	for(int counter=s; counter<=k-1; counter++){
		arr[counter] = temp[counter];
	}
}


void mergesort(int arr[], int s, int e){
	//Base Case
	if(s>=e){
		return;
	}
	//recursive Case
	int mid = (s+e)/2;
	mergesort(arr, s, mid);
	mergesort(arr, mid+1, e);

	merge(arr, s, e);

}



int main(){
	int arr[10]  = {10,9,8,7,6,5,4,3,2,1};
	int n=10;
	mergesort(arr, 0, n-1);
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}