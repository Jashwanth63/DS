#include <iostream>
#include <string>

using namespace std;

void getSubstring(string &s, int i, int len, string temp){
	if(i==len){	
		cout<<temp<<" ";
		return;
	}
	temp = s[i];
	getSubstring(s, i+1, len, temp);
	temp += 
	getSubstring(s, i, len, temp);

}



int main(){
	string s="abcde";
	string temp;
	getSubstring(s, 0, s.length(), temp);
	return 0;
}