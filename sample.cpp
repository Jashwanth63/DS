#include<iostream>
#include<string>
#include<climits>
#include<vector>
#include<unordered_set>


using namespace std;

    
void findWord(vector<vector<string>> &ans, string &x, vector<string> temp, unordered_set<string> &words, int i, int &len, bool isPresent){
    if(i  >= len){
        //cout<<"x";
        if(isPresent){
            //cout<<"x";
            
            //cout<<"x";
            ans.push_back(temp);
        }
        return;
    }
    isPresent = false;
    for(int z = 0; (z+i)<len; z++){
        //cout<<"working";
        string curr = x.substr(i, z+1);
        cout<<i<<" "<<z<<" ";
        cout<<curr<<" "<<endl;
        if(words.find(curr) != words.end()){ //If found
            isPresent = true;
            //cout<<endl<<curr<<endl;
            temp.push_back(curr);
            findWord(ans, x, temp, words, i+z+1, len, isPresent);
            temp.pop_back();
            isPresent = false;
            //findWord(ans, x, temp, words, i, z+1, len, false);
            //cout<<"X";
        }   
    }
    
    return;
}


vector<string> displayVec(vector<vector<string>> &ans){
    vector<string> final;
    for(auto sentence: ans){
        string curr;
        for(auto word: sentence){
            curr += word + " ";
        }
        cout<<curr;
        final.push_back(curr);
        cout<<endl;
    }
    return final;
}


int main(){
    unordered_set<string> words{"apple", "pen", "epen", "appl"};
    string x = "penapplepen";
    vector<vector<string>> ans;
    int len = x.length();
    bool isPresent = false;
    vector<string> temp;
    
    findWord(ans, x, temp, words, 0, len, isPresent);

    //display1D(converttoSentence);
    //cout<<"done";
    vector<string> final = displayVec(ans);

    return 0;

}