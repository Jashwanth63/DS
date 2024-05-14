class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int slen = s.length();
        int tlen = t.length();
        while(i<slen && j<tlen){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
            
        }
        return i==slen ? true:false;
    }
};