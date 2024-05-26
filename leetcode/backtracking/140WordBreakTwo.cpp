class Solution {
public:
    void findWord(vector<vector<string>> &ans, string &x, vector<string> temp, unordered_set<string> &words, int i, int &len, bool isPresent){
        if(i  >= len){
            if(isPresent){
                ans.push_back(temp);
            }
            return;
        }
        isPresent = false;
        for(int z = 0; (z+i)<len; z++){
            string curr = x.substr(i, z+1);
            cout<<i<<" "<<z<<" ";
            cout<<curr<<" "<<endl;
            if(words.find(curr) != words.end()){ //If found
                isPresent = true;
                temp.push_back(curr);
                findWord(ans, x, temp, words, i+z+1, len, isPresent);
                temp.pop_back();
                isPresent = false;
            }   
        }
        
        return;
    }

    vector<string> displayVec(vector<vector<string>> &ans){
        vector<string> final_ans;
        for(auto sentence: ans){
            string curr;
            int counter = 0;
            for(auto word: sentence){
                if(counter == sentence.size()-1){
                    curr += word;
                    break;    
                }
                curr += word + " ";
                counter++;
            }
            //cout<<curr;
            final_ans.push_back(curr);
            //cout<<endl;
        }
        return final_ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> tempDict;
        for(auto word: wordDict){
            tempDict.insert(word);
        }
        vector<vector<string>> ans;
        int len = s.length();
        
        bool isPresent = false;
        vector<string> temp;
        
        findWord(ans, s, temp, tempDict, 0, len, isPresent);

        //display1D(converttoSentence);
        //cout<<"done";
        vector<string> final_ans = displayVec(ans);
        return final_ans;
    }
};