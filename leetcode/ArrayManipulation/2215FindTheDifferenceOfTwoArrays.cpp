class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        // Find left union, right union and subtract intersection, for each nums
        set<int> num1;
        set<int> num2;
        int len1 = nums1.size();
        int len2 = nums2.size();
        for(int i=0; i<len1; i++){
            if(num1.find(nums1[i]) == num1.end()) num1.insert(nums1[i]);
        }
        for(int i=0; i<len2; i++){
            if(num2.find(nums2[i]) == num2.end()) num2.insert(nums2[i]);
        }
        //For nums1
        for(auto num : num1){
            if(num2.find(num) == num2.end()){
                ans[0].push_back(num);
            }
            else{
                num2.erase(num);
            }
        }
        //For 2
        for(auto num: num2){
            ans[1].push_back(num);
        }
        return ans;
    }
};