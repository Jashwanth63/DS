#include <iostream>
#include <string>

using namespace std;


void subs(string &s, int size, int start, string &temp){
	if(size-1 == start){
		cout<<temp<<" ";
	}
	temp  += s[start];
	subs(s, size, start+1, temp);
	temp[temp.length()-1] = '\0';
	subs(s, size, start+1, temp);


}


int main(){
	string s = "xbfb";
	string temp = "";
	subs(s, s.length(), 0, temp);

	return 0;
}