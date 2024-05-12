#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<cctype>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j = s.length()-1;
        while(i<=j){
            if(tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }
            else if(!isalpha(s[i])){
            	//cout<<s[i]<<" ";
                i++;
            }
            else if(!isalpha(s[j])){
            	//cout<<s[j]<<" ";
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

int main(){
	string s = "A man, a plan, a canal: Panama";
	Solution str = Solution();
	cout<<str.isPalindrome(s);
	return 0;
}