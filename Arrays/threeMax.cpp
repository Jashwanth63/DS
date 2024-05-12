#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first, second, third;
        first = nums[0];
        int num_len = nums.size();
        if(num_len==1){
            return first;
        }
        second = min(nums[1], first);
        if(num_len==2){
            return max(nums[1], first);
        }
        third = INT_MIN;
        for(int i=2;i<num_len; i++){
            first = max(first, nums[i]);
            second = (nums[i]<first && nums[i]>third && nums[i]>=second)?nums[i]:second;
            if(nums[i]<first && nums[i]<second && nums[i]>=third){
                third = nums[i];
            }
        cout<<first<<" "<<second<<" "<<third <<endl;
        }

        return third>INT_MIN ? third:first;
    }
};

int main(){
    Solution s = Solution();
    vector<int> temp{2,2,1,1,1};
    cout<<s.thirdMax(temp);
    return 0;
}