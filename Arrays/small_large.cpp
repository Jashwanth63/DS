#include <iostream>
#include <climits>
using namespace std;


int main(){
	int arr[10] = {10,11,12,13,154,1,2,3,-2,116};
	int smallest = INT_MAX;
	int largest = INT_MIN;

	for(int i=0; i<10; i++){
		if(arr[i] < smallest){
			smallest = arr[i];
		}
		if(arr[i] > largest){
			largest = arr[i];
		}
	}

	cout<<"Smallest value in the array is: "<<smallest<<endl;
	cout<<"Largest value in the array is: "<<largest<<endl;
	return 0;
}