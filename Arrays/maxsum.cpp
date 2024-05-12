#include <iostream>
#include <climits>
using namespace std;

int main(){	
	int arr[9];
	int max = INT_MIN;
	int min_index=-1, max_index=-1;
	int sum=0;
	for(int i=0; i<9; i++){
		cin>>arr[i];
	}
			
	for(int i=0; i<9; i++){
		for(int j=i; j<9; j++){
			for(int k=i; k<=j; k++){
				sum += arr[k];
			}

			if(sum > max){
				max = sum;
				min_index = i;
				max_index = j;
			}
			sum = 0;
		}
	}
	cout<<endl<<max<<endl<<min_index<<" "<<max_index;
	return 0;
}