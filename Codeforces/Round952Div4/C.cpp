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
		int n;
		cin>>n;
		vector<ll> arr(n, 0);
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}

		ll sum = 0;
		ll maximum = LONG_MIN;
		int count = 0;
		for(int i=0; i<n; i++){
			sum += arr[i];
			maximum = max(maximum, arr[i]);
			if((sum-maximum) == maximum) count++;
		}
		cout<<count<<endl;
	}

	return 0;
}


