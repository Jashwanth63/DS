class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        // Two ways, sort and compare
        // or, count and compare
        unordered_map<char, int> counts;
        for(int i=0; i<s.length(); i++){
            counts[s[i]]++;
        }    

        // Check if t[i] exists in counts and whether counts[t[i]] > 0, can do in one step
        for(int i=0; i<t.length(); i++){
            if(counts[t[i]]>0) counts[t[i]]--;
            else return false;
        }
        return true;
    }
};  