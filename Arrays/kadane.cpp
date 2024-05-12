//This also works for Negative numbers
#include <iostream>
#include <climits>
using namespace std;
 
int main(){
	int arr[100] = {0};
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	int cumsum=0, maxsum=0;
	int for_negs = INT_MIN;
	for(int i=0; i<n; i++){
		cumsum = max(cumsum+arr[i], 0);
		maxsum = max(cumsum, maxsum);
		for_negs = max(for_negs, arr[i]);
	}
	if(maxsum == 0){
		maxsum = for_negs;
	}
	cout<<"Maximum is "<<maxsum;
	return 0;
}