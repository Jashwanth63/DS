class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> counts;
        int len = s.length();
        for(int i=0; i<len; i++){
            counts[s[i]]++;
        }
        bool isOdd = false;
        int totalLen = 0;
        for(auto kv: counts){
            if(kv.second % 2 == 0) totalLen += kv.second;
            else{
                isOdd = true;
                totalLen += kv.second - 1;
            }  
        }
        if(isOdd) totalLen++;
        return totalLen;
    }
};