#include <iostream>
#include <climits>

using namespace std;

int main(){
	int a[10] = {20,10,8,5,-2,-10,100,70,50,101};
	int mini  = INT_MIN;
	int maxi = INT_MAX;
	int n = sizeof(a) / sizeof(int); 
	/*Method 1
	for(int i=0; i<n; i++){
		if(a[i] < maxi){
			maxi = a[i];
		}
		if(a[i] > mini){
			mini = a[i];
		}
	}
	*/
	//Method 2
	for(int i=0;i<n;i++){
		mini = max(mini, a[i]);
		maxi = min(maxi, a[i]);
	}
	cout<<"Minimum: "<<maxi<<endl<<"Maximum: "<<mini;
	return 0;
} 