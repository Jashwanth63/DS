class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        unordered_map<int, int> a1;
        for(int i=0; i<len-1; i++){
            unordered_map<int, int> twoSum;
            int a = nums[i];
            if(a1.find(a) != a1.end()) continue;
            a1[a] = 0;
            int sum = 0 - a;
            unordered_map<int, int> b1;
            int x=i+1;
            int y=len-1;
            while(x<y){
                int total = nums[x] + nums[y];
                if(total == sum && b1.find(nums[x]) == b1.end()){
                    ans.push_back({a, nums[x], nums[y]});
                    b1[nums[x]] = 0;
                    x++;
                    y--;
                } 
                else if(total>sum){
                    y--;
                }
                else{
                    x++;
                }
            }
        }
        return ans;

    }
};