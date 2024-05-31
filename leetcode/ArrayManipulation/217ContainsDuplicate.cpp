class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> nc;
        for(int i:nums){
            nc[i]++;
            if(nc[i]>1){
                return true;
            }
        }
        return false;
    }
};