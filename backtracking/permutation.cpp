#include <iostream>
#include <vector>
using namespace std;


void findAllPerm(int arr[], int i, int j){
	if(i==j){
		for(int temp=0; temp<j; temp++){
			cout<<arr[temp]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int temp = i; temp<j; temp++){
		swap(arr[i], arr[temp]);
		findAllPerm(arr, i+1, j);
		swap(arr[i], arr[temp]);
	}
}


int main(){
	int arr[4] = {1,1,2,3};
	//vector<int> arr{1,2,3};
	int size = sizeof(arr) / sizeof(int);
	findAllPerm(arr, 0, 4);
	return 0;
}