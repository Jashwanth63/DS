#include <iostream>

using namespace std;

int binary_search(int arr[], int n, int element){
	int start = 0;
	int end = n;
	while(start <= end){
		int mid = (start + end) / 2;
		if(arr[mid] == element){
			return mid;
		}
		else if(arr[mid] < element){
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	return -1;
}


int main(){
	int arr[2] = {1,2};
	int element;
	int n = sizeof(arr)/sizeof(int);
	cout<<"Enter Element to Search: ";
	cin>>element;
	cout<<endl;
	int ans = binary_search(arr, n, element);
	cout<<endl<<"Element Found at Position: "<<ans;
	return 0;
}