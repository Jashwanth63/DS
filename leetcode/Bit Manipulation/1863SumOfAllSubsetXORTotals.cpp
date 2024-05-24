class Solution {
    //vector<vector<int>> subsets;
    void make_subsets(vector<int> &nums, int i, int len, int &ans, int XOR){
        if(i == len){
            ans += XOR;
            return;
        }
        make_subsets(nums, i+1, len, ans, XOR ^ nums[i]);
        make_subsets(nums, i+1, len, ans, XOR);
    }


public:
    int subsetXORSum(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        make_subsets(nums, 0, len, ans, 0);
        return ans;
    }
};