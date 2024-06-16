class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        bool canJump = false;
        if(len == 1) return true;
        int stepsRequired = 1;
        for(int i=len-2;i>=0; i--){
            canJump = false;
            int availableSteps  = nums[i];
            int toJump = availableSteps - stepsRequired;
            if(toJump >= 0){
                canJump = true;
                stepsRequired = 0;
            }  
            stepsRequired++;
        }
        return canJump;
    }
};