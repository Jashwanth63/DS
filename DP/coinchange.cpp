#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> dp(10001, -1);

int mincoins(vector<int> denominations, int amount){
	if(amount == 0){
		return 0;
	}
	if(dp[amount]!=-1){
		return dp[amount];
	}
	int mini = INT_MAX;
	for(int i=0; i<denominations.size(); i++){
		if(amount>=denominations[i]){
			mini = min(mini, mincoins(denominations, amount - denominations[i]));				
		}
		else{
			break;
		}

	}
	
	return dp[amount] = mini+1;
}


int bottomup(vector<int> denominations, int amount){
	int length = denominations.size();
	for(int j=1; j<=amount; j++){
		int ans = INT_MAX;
		for(int i=0; i<length; i++){
			if(j-denominations[i] >=0){
				if(dp[j - denominations[i]] == 0){
					ans = -1;
					break;
				}
				ans = min(ans, dp[j - denominations[i]]);	
			}
			else{
				break;
			}
		}
		dp[j] = ans+1;
	}
	return dp[amount];	
	
	
}

int main(){
	int amount;
	vector<int> denominations{1, 7,10};
	cin>>amount;

	int ans = mincoins(denominations, amount);
	
	//int ans = bottomup(denominations, amount);
	cout<<ans;
	
	return 0;
} 