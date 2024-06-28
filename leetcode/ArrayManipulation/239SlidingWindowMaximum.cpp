class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> ans(len-k+1);
        deque<int> numbers;
        for(int i=0; i<k; i++){
            while(!numbers.empty() && nums[numbers.back()] < nums[i]) numbers.pop_back();
            numbers.push_back(i);
        }
        ans[0] = nums[numbers.front()];
        for(int i=k; i<len; i++){
            while(!numbers.empty() && numbers.front() <= i-k) numbers.pop_front(); // This is Counter-Intuitive. Watch NeetCode Video To revise. 
            while(!numbers.empty() && nums[numbers.back()] < nums[i]) numbers.pop_back();
            numbers.push_back(i);
            ans[i-k+1] = nums[numbers.front()];
        }
        return ans;
    }
};