#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>> ans;
        unordered_map<vector<int>, vector<string>, VectorHasher> anagrams;
        for(int i=0; i<len; i++){
            vector<int> characters(26, 0);
            for(int j=0; j<strs[i].length(); j++){
                characters[strs[i][j] - 97] += 1;
            }
            anagrams[characters].push_back(strs[i]);
        }

        for(auto it: anagrams){
            ans.push_back(it.second);
        }
        return ans;
    }
};


int main(){


    return 0;
}