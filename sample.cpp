class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<bool> visited(len, false);
        vector<vector<string>> ans;
        for(int i=0; i<len; i++){
            if(visited[i]) continue;
            unordered_map<char, int> counts;
            vector<string> temp;
            temp.push_back(strs[i]);
            visited[i] = true;
            int i_len = strs[i].length();
            // Do count for ith
            for(int k=0; k<i_len; k++){
                counts[strs[i][k]]++;
            }

            for(int j=0; j<len; j++){
                if(j == i || visited[j]) continue;
                unordered_map<char, int> tempCount(counts);
                if(i_len != strs[j].length()) continue;
                else{
                    int m_len = strs[j].length();
                    for(int m=0; m<m_len; m++){
                        if(tempCount[strs[j][m]] > 0){
                            visited[j] = true;
                            tempCount[strs[j][m]]--;
                        } 
                        else{
                            visited[j] = false;
                            break;
                        } 
                    }
                    if(visited[j]) temp.push_back(strs[j]);  
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
