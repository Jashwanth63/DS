// Three Approaches.

// 1. Sort and search for every [0, len] -> O(N^2)
// 2. Sort and Binary search for [0, len] -> O(NlogN + N^2logN), For first occurence
// 3. Binary Search on [0, len] -> O(NlogN + logNlogN) -> with Two Binary Searches

// Method 3
class Solution {
public:
    // Method 3
    // Binary Search On [0, length]
    int specialArray(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int len = nums.size();
       int s = 1;
       int e = len;
       int count = 0;

       while(s<=e){
            int mid = s + (e-s)/2;
            int index = binarySearch(nums, 0, len-1, mid);
            if(index >= len) return -1;
            int ans = len - index;
            if(ans == mid) return mid;
            else if(ans > mid){
                s = mid+1;
            }
            else{
                e = mid-1;
            } 
       }
       return -1;
    }



    int binarySearch(vector<int> &nums, int s, int e, int x){
        // With First Occurence
        int mid; 
        while(s<=e){
            mid = s + (e-s)/2;
            if(nums[mid] == x){
                e = mid-1;
            }
            else if(nums[mid] < x) {
                s = mid+1;
            } 
            else{
                e = mid-1;
            }
        }
        return s;
    }
};



// Method 2
/**
class Solution{
    int binarySearch(vector<int> &nums, int s, int e, int x){
        // With First Occurence
        int mid; 
        while(s<=e){
            mid = s + (e-s)/2;
            if(nums[mid] == x){
                e = mid-1;
            }
            else if(nums[mid] < x) {
                s = mid+1;
            } 
            else{
                e = mid-1;
            }
        }
        return s;
    }

    int specialArray(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int len = nums.size();
       int count = 0;
       for(int i=1; i<=len; i++){
            int index = binarySearch(nums, 0, len-1, i);
            cout<<index<<" ";
            if(index >= len) return -1;
            if((len - index) == i) return i;
       }
       return -1;
    }
};


**/

//Method 1
//Brute Force With O(N^2)
/**
class Solution{
    int specialArray(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int len = nums.size();
       int count = 0;
       for(int i=0; i<=len; i++){
            count = 0;
            for(int j=0; j<len; j++){
                if(nums[j] >= i){
                    count = len - j;
                    break;
                }
            }
            if(count == i) return i;
       }
       return -1;
    }
};
**/

