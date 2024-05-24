/**
 *  1. Count all letters
 *  2. Find all subsets of words
 *  3. For each word, check if it can be in the subset (it can be if count of letters in word is less than count of total letters available)
 *     If valid, set include to true and recur from the next word in words.
 *  4. Remove all operations done on the current word when backtracking.
 *  5. When i == n find max of currSum and maxSum. 
 *  (Time Complexity -> O(2^n * m)). Can be optimized with memoization. but how???
 **/ 


class Solution {
public:
    void findSubsets(vector<string> &words, int i, int n, unordered_map<char, int> countLetter, vector<int> &score, int currSum, int &maxSum, bool include){
        if(i == n){
            maxSum = max(currSum, maxSum);
            return;
        }
        unordered_map<char, int> tempCount;
        int sumCount = 0;

        for(char &letter : words[i]){
            if(countLetter.find(letter) != countLetter.end() && countLetter[letter]>0) {
                tempCount[letter]++;
                countLetter[letter]--;
                sumCount += score[letter-97];
                include = true;
                
            }
            else{
                for(char &l : words[i]){
                    if(tempCount.find(l) != tempCount.end() && tempCount[l]>0){
                        countLetter[l]++;
                        tempCount[l]--;
                    } 
                }
                include= false;
                sumCount = 0;
                indexInclude[i] = false;
                break;
            } 
        }
    
        if(include) currSum += sumCount;

        findSubsets(words, i+1, n, countLetter, score, currSum, maxSum, include);

        if(include) {
            for(char &l : words[i]){
               countLetter[l]++; 
            } 
            currSum -= sumCount;
        }
        
        findSubsets(words, i+1, n, countLetter, score, currSum, maxSum, include);
    }
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> countLetter;
        for(char &i: letters) countLetter[i]++;
        int start = 0;
        int end = words.size();
        int currSum = 0;
        int maxSum = INT_MIN;
        bool include = false;
        findSubsets(words, 0, end, countLetter, score, currSum, maxSum, include);
        return maxSum!=INT_MIN ? maxSum : 0;

    }
};