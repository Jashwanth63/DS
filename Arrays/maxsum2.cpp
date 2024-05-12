#include <iostream>
#include <climits>
using namespace std;


int main(){
	int arr[100];
	int cumsum[100];
	int n=5;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(i==0){
			cumsum[i] = arr[i];
		}
		else{
			cumsum[i] = cumsum[i-1] + arr[i];
		}
	}
	int max = INT_MIN;
	int sum = 0;
	int min_index;
	int max_index;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(i==0){
				sum = cumsum[j];
			}
			else{
				sum = cumsum[j] - cumsum[i-1];
			}
			if(sum > max){
				max = sum;
				min_index = i;
				max_index = j;
			}
			sum = 0;

		}

		
		
	}
	/*
	for(int i=0;i<n; i++){
		cout<<cumsum[i]<<" ";
	}
	*/
	cout<<max<<" "<<min_index<<","<<max_index;
	return 0;
}