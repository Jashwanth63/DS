#include <vector>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // water_between_two = (j-i) * min(height[i], height[j])
        int water_now = 0;
        int min_hdifference = INT_MAX;
        int start = 0;
        int end = 1;
        int max_water = 0;
        for(int i=1; i<height.size(); i++){
            water_now = (i-start) * min(height[i], height[start]);
            max_water = max(water_now, max_water);
            min_hdifference = min(min_hdifference, abs(height[start]-height[end]));
            if(min_hdifference >= abs(height[i]-height[end]) && (i-end)>0){
                //min_hdifference = min(min_hdifference, abs(height[i]-height[end]));
                int water_temp = (i-end) * min(height[i], height[end]);
                if(water_temp >= max_water and water_temp>0){
                    start = end;
                    end = i;
                    max_water = water_temp;
                }
                else{
                    end = i;
                }
                
            }
            //end=i;
            
            //cout<<min_hdifference<<" ";
            //cout<<water_now<<endl;
            cout<<start<<" ";
        }
        return max_water;
    }
};

int main(){
    vector<int> height{1,0,0,0,0,0,0,2,2};
    Solution s = Solution();
    cout<<s.maxArea(height);
    return 0;
}