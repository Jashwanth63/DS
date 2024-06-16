static const int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> indices;
        int len = nums.size();
        for(int i=0; i<len; i++){
            if(indices.find(nums[i]) != indices.end()){
                int calc = abs(indices[nums[i]] - i);
                if(calc <= k) return true; 
            }
            indices[nums[i]] = i;
        }
        return false;
    }
};