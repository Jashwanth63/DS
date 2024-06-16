#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <list>


typedef long long ll;
typedef long l;

using namespace std;


int main(){
	int T;
	cin>>T;
	while(T--){
		string a, b;
		cin>>a>>b;
		swap(a[0], b[0]);
		cout<<a<<" "<<b;
		cout<<endl;
	}

	return 0;
}


