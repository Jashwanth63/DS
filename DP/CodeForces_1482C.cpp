// Code name: Balls

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int> arr(n);
		int maxVal = 0;
		vector<int> dp(n);
		for(int i=0; i<n; i++){
			cin>>arr[i];
			if(dp[arr[i]] > 0){
				maxVal += max(maxVal, i-dp[arr[i]]);
			}
			else{
				dp[arr[i]] = i;	
			}
		}
		cout<<maxVal+1<<endl;
	}

	return 0;
}
