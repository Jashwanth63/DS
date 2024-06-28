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
		cin>>a>>b;
		cin>>c>>d;
		if(a<b && c>d) cout<<"NO";
		else if(a>b && c<d) cout<<"NO";
		else if(a<=b && c<=d) cout<<"YES";
		else if(a>=b && c>=d) cout<<"YES";
		cout<<endl;

	}

	return 0;
}


