#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;


int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int> nums(n);
		int storeMax = INT_MIN;
		int at = -1;
		for(int i=0; i<n; i++){
			cin>>nums[i];
			if(storeMax <= nums[i]) at = i;  
			storeMax = max(storeMax, nums[i]);
		}
		if(at == 0) cout<<storeMax + nums[n-1];
		else if(at == n-1) cout<<storeMax + nums[n-2];
		else cout<<storeMax + nums[n-1];

		cout<<endl;

	}
	return 0;
}