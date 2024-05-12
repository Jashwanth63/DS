#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int end){
		
	int mid = (start+end)/2;
	int i=start;
	int j=mid+1;
	int k=start;

	vector<int> temp(100001);

	while(i<=mid && j<=end){
		if(arr[i] > arr[j]){
			temp[k++] = arr[j++];
		}
		else{
			temp[k++] = arr[i++];
		}
	}

	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=end){
		temp[k++] = arr[j++];
	}

	for(int x=start; x<k; x++){
		arr[x] = temp[x];
	}

}


void mergeSort(vector<int> &arr, int start, int end){
	if(start>=end){
		return;
	}
	int mid = start + (end-start)/2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid+1, end);

	merge(arr, start, end);

}

int main(){
	vector<int> arr{-10,-9,5,4,3,2,1};
	mergeSort(arr, 0, arr.size()-1);
	for(int i: arr){
		cout<<i<<" ";
	}


}