#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	string s = "{}";
	stack<char> param;
	cout<<param.top();
	for(int i=0; i<s.length(); i++){
		if(s[i] == param.top()){
			param.pop();
		}
		else{
			param.push(s[i]);
		}
		
	}
	if(param.empty()){
		cout<<param.top();
	}
	else{
		cout<<param.top();
	}


	return 0;
}