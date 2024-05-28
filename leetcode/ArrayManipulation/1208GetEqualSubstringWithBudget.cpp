class Solution {
public:

    bool doWindow(string &s, string &t, int &maxCost, int mid, vector<int> &costs){
        int len = t.length();
        int CurrCost= INT_MAX;
        for(int i=0; (i+mid)<=len; i++){
            if(i==0){
                CurrCost = min(CurrCost, costs[mid-1]);
            }
            else{
                CurrCost = min(CurrCost, costs[i+mid-1]-costs[i-1]);
            }
        }
        if(CurrCost <= maxCost) return true;
        return false;
    }

    // Binary Search on len of t, if substring can be formed s = mid+1, else e = mid-1
    int equalSubstring(string s, string t, int maxCost) {
        // window ? 

        int start = 0 ;
        int end = t.length() - 1;
        
        vector<int> costs(end+1, 0);
        costs[0] = abs(s[0] - t[0]);
        int counts = 0;  
        for(int i=1; i<=end; i++){
            costs[i] = costs[i-1] + abs(s[i] - t[i]);
        }
        int maxLen = 0;
        int CurrCost = INT_MAX;
        while(start <= end){
            int mid = start + (end-start)/2;
            bool temp = doWindow(s, t, maxCost, mid+1, costs);
            if(!temp){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
};