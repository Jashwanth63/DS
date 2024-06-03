class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        while(i<s.length() && j<t.length()){
            //if(j==t.length()-1) return 0;
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return t.length() - j;
    }
};