#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Steps from i -> n-1-i
        int n = nums.size();
        vector<bool> dp(n, 0);
        dp[n-1] = true;
        int i=n-2;
        if(n==1) return true;
        while(i>=0){
            int temp = nums[i];
            if((n-1-i)<=temp) dp[i]=true;
            else{
                while(temp){
                    if(!dp[temp+i]) continue;
                    else{
                        dp[i]=true;
                        break;
                    }
                    temp--;
                }
            }
            cout<<dp[i]<<" ";
            i--;
        }
        return dp[0];
    }
};

int main(){
	Solution s = Solution();
	vector<int> x{1,1,1,1,0};
	cout<<endl<<s.canJump(x);


	return 0;
}