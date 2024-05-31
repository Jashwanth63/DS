#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



// Three ways

// 1. Brtue Force - O(M * Mlen * N * Nlen)
// 2. Each string will have upto 26 unique characters. Store count of each string in vector, 
//    hash this function using custom function, and use this as key. - O(M*N) , here custom hashing 
//                                                                              takes a bit more time
// 3. Sort string and use as key. Value will be vector of unsorted string - O(M*N)


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