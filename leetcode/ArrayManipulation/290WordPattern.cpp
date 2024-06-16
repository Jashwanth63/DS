class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> matches;
        int PatLen = pattern.length();
        int sLen = s.length();
        int j=0;
        unordered_map<string, char> reverseMatch;
        for(int i=0; i<PatLen; i++){
            if(j == sLen || j==sLen+1) return false;
            string curr;
            while(j!=sLen && s[j]!=' '){
                curr += s[j];
                j++;
            }
            j++;
            if(reverseMatch.find(curr) != reverseMatch.end()){
                if(reverseMatch[curr] != pattern[i]) return false;
            }
            else{
                reverseMatch[curr] = pattern[i];
            }
            
            // If there is a key. 
            if(matches.find(pattern[i]) != matches.end()){
                if(matches[pattern[i]] != curr) return false;
            }
            else {
                matches[pattern[i]] = curr;
            }
        }
        if(j!=sLen+1) return false;
        return true;
    }
};