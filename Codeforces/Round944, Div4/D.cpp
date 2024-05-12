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
		int i, j;
		int len = s.length();
		i=0;
		j=1;
		int count=0;
		while(j<len){
			if(s[j]=='1'){
				if(s[i]=='1' && s[j-1]=='0') count++;
				i=j;
			}
			++j;
			
		}
		if(s[j]=='0' && s[i]=='1') count++;
		cout<<count+1<<endl;
	}

	return 0;
}


