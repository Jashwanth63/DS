#include<iostream>
#include<vector>
using namespace std;

int bin_search(vector<int> &arr, int beg, int end, int element){
	if(beg>=end){
		return -1;
	}
	int mid = (beg+end)/2;
	int index;
	if(arr[mid] == element){
		return mid;
	}
	else if(arr[mid] < element){
		index = bin_search(arr, mid, end, element);
	}
	else {
		index = bin_search(arr, beg, mid, element);
	}

	return index;
}


int main() {
	int n;
	vector<int> arr;
	int element;
	cin>>n;
	//arr.reserve(n);
	for(int i=0; i<n; i++){
		cin>>element;
		arr.push_back(element);
	}
	cin>>element;
	int beg = 0;
	int end = n;
	cout<<bin_search(arr, beg, end-1, element);
	

	return 0;
}