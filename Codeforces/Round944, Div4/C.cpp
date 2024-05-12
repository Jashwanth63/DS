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
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		pair<int, int> one;
		pair<int, int> two;
		one.first = a<b?a:b;
		one.second = a<b?b:a;

		two.first = c<d?c:d;
		two.second = c<d?d:c;
		int count = 0;
		for(int i=one.first; i<=one.second; i++){
			if(i==two.first || i==two.second) count++;
		}
		if(count==2 || count==0) cout<<"NO";
		else cout<<"YES";
		cout<<endl;
	}

	return 0;
}


