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
		int a,b;
		cin>>a>>b;
		cout<<min(a,b)<<" "<<max(a,b);
		cout<<endl;
	}

	return 0;
}


