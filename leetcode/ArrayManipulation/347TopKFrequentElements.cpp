#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts; // num, count of num
        int len = nums.size();
        int maxCount = INT_MIN;
        
        for(int i=0; i<len; i++){
            counts[nums[i]]++;
            maxCount = max(counts[nums[i]], maxCount); // Find max count of mode/s. 
        }

        // We initialize to -1001 because nums[i] is in the range [-10000, 10000]
        vector<vector<int>> topK(maxCount+1, vector<int>(1, -1001)); // initialze vector of size max count
        // We use the indices of this vector as placeholders for our modes. 
        // Index of topK -> Counts, Values at index of topK -> vector of nums with that count
        // Example: [1,1,1,2,2,3]
        // 1 -> 3 (1 appears 3 times, in vector topK, at index 3 set value to 1. )
        // 2 -> 2
        // 3 -> 1

        // Values that don't appear in range [0, maxCount] will be -1001
        // We have a vector of vector because for the same frequency we can have multiple values.
        // Since the answer is unique the order of storing them doesn't matter

        vector<int> ans; // answer to return
        for(auto &b: counts){ // b.first is num, b.second is count. b.second/count is index for topK
            if(topK[b.second][0] == -1001){ // If value was initially -1001, set that to b.first
                topK[b.second][0] = b.first;
            }
            else{ // If there is another number for b.second, just push back b.first
                topK[b.second].push_back(b.first);    
            }
        }

        // Decrement iteratively from the back of topK untill K elements are found
        for(int i=topK.size()-1; i>=1; i--){ 
            if(k == 0) break;
            while(k>0 && topK[i].size()>0){
                if(topK[i][0] != -1001 && k!=0){ // Ignore the indices that have -1001. 
                    ans.push_back(topK[i][0]);
                    k--; //Everytime we push to ans, decrement k
                    topK[i].erase(topK[i].begin());  // erase the first element from topK[i]
                }
                else{
                    break;
                }
            }
            
        }
        return ans;
    }
};


int main(){
    // intentionally left blank
    return 0;
}