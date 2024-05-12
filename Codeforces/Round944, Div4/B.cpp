#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <string>
#include <cmath>
#include <algorithm>



typedef long long ll;
typedef long l;

using namespace std;


int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int len = s.length();
		int i=1;
		while(i<len){
			if(s[i] == s[i-1]){
				i++;
				continue;
			} 
			else{
				cout<<"YES"<<endl;
				swap(s[i], s[i-1]);
				cout<<s<<endl;
				break;
			}
		}
		if(i >= len) cout<<"NO"<<endl; 
	}

	return 0;
}


