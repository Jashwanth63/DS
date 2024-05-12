#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
	string move(string &tofind, int start, int end){
		char temp = tofind[end];
		while(end>start){
			tofind[end] = tofind[end-1];
			end--;
		}
		tofind[start] = temp;
	}

    void doPerm(string &toFind, int n, int i, int k, int &counter, string &ans){
        if(!toFind.empty() && i==n){
            counter++;
            if(counter == k){
                ans = toFind;
                toFind.clear();
            }
            return;
        }
        
        for(int temp=i; temp<n; temp++){
        	move(toFind, i, temp);
            //swap(toFind[i], toFind[temp]);
            doPerm(toFind, n, i+1, k, counter, ans);
            if(!toFind.empty()){
                move(toFind, i, temp);
            }
            else{
                return;
            }
        }
        return;
    }
    string getPermutation(int n, int k) {
        string toFind = "";
        string ans;
        int counter = 0;
        char end = char(48+n);
        for(char i='1'; i<=end; i++){

            toFind += i;
        }
        doPerm(toFind, n, 0, k, counter, ans);
        return ans;
    }
};

int fact(int n){
	if(n==1){
		return n;
	}
	return n*fact(n-1);
}

int main(){
	Solution s = Solution();
	for(int i=1; i<=fact(3); i++){
		cout<<s.getPermutation(3, i)<<endl;
	}

	return 0;
}