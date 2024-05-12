//Given a sorted array, find the pair that sums to K
#include <iostream>
using namespace std;
//If array is unsorted, sort it. 
void bubblesort(int arr[], int n){
	for(int i=n-1; i>0; i--){
		for(int j=0; j<=i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}
int main(){
	int arr[1000] = {0};
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	//display array
	bubblesort(arr, n); 

	//After sorting
	int k;
	cin>>k;

	//Two pointer Approach
	int i=0, j=n-1;
	while(i!=j){
		int total = arr[i]+arr[j];
		if(total == k){
			break;
		}
		else if(total > k){
			j--;
		}
		else if(total < k){
			i++;
		}
	}
	if(i==j){
		cout<<endl<<"Pair Not Found";
	}
	else{
		cout<<endl<<"Pairs at indices: "<<i<<" and "<<j<<" "<<"In the sorted Array";	
	}

	return 0;
}