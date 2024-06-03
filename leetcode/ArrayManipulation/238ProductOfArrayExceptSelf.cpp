#include <iostream>
#include <vector>

using namespace std;

// Three Methods: 1. Brute Force - O(N^2)
// 2. Prefix and postfix for each i, excluding i in calc. SC: O(N), TC: O(N)
// 3. Store the prefix and postfix in the ans vector. SC: O(1), TC: O(N)



// Three-pass with O(N) space complexity

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len, 1);
        vector<int> postfix(len, 1);
        int pro = 1;
        for(int i=0; i<len; i++){
            if(i-1 == -1) continue;
            else{
                pro *= nums[i-1];
                prefix[i] = pro;
            }
        }
        pro = 1;
        for(int i=len-1; i>=0; i--){
            if(i+1 == len) continue;
            else{
                pro *= nums[i+1];
                postfix[i] = pro;
            }
        }
        // Multiply both
        vector<int> ans(len, 1);
        for(int i=0; i<len; i++){
            ans[i] = prefix[i] * postfix[i];
        }
        return ans;
    }
};





// Two-Pass with O(1) space complexity

class Solution1 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int len = nums.size();
        vector<int> product(len, 1);
    
        for(int i=1; i<len; i++){
           product[i] = nums[i-1]*product[i-1];
        }

        int pro = 1;
        for(int i=len-2; i>=0; i--){
            pro = pro * nums[i+1];
            product[i] *= pro ;
            
        }
        return product;
    }
};

int main(){

	return 0;
}