#include <iostream>

using namespace std;

int main(){
	int arr[100000] = {0};
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	int i=0;
	int j=n-1;
	int total_water = 0;
	while(i<j){
		for(int q=j-1; q>=i+1; q--){
			if(arr[q] >= arr[j]){
				j = q;
			}
		}
		for(int q = i+1; q<=j-1; q++){
			int block_index = i;
			if(arr[q] >= arr[i]){
				block_index = q;
				int small_block_size = min(arr[q], arr[i]);
				for(int w=i+1; w<q; w++){
					total_water += small_block_size - arr[w]; 
				}
			}
			
			i = block_index;
		}
		int small_block_size = min(arr[i], arr[j]);
		for(int q=i+1; q<j; q++){
			total_water += small_block_size - arr[q];
		}
		i=j;
		j=n-1;
	}

	cout<<total_water;

	return 0;
}