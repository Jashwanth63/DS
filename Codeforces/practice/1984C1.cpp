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
		ll sum1 = 0;
		ll sum2 = 0;
		ll c = 0;
		for(int i=0; i<n; i++){
			if(arr[i] < 0){
				sum1 = sum1+arr[i];
				c = max(abs(c+arr[i]), c+arr[i]);
			}
			else{
				sum1 = sum1+arr[i];
				c= c+arr[i];
			}
		}
		cout<<max(abs(sum1), c)<<endl;
	}

	return 0;
}


