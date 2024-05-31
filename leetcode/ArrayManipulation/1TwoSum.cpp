class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // One - Pass, Tricky to understand. not straightforward. Read Notes.
        unordered_map<int, int> indices;
        int len = nums.size();
        for(int i=0; i<len; i++){
            int diff = target - nums[i];
            if(indices.find(diff) != indices.end()){
                return {i, indices[diff]};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};

// Two Pass
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> num;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            num[nums[i]] = i;
        }

        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if((num.find(diff) != num.end())){
                if(num[diff]!=i){
                    ans.push_back(i);
                    ans.push_back(num[diff]);
                    break;  
                }
                
            }
        }
        return ans;
    }
};


//Third Method is to sort and use two pointers


