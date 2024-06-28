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
		vector<int> nums(3, 0);
		int minimum = 11;
		int maximum = 0;
		for(auto &x: nums){
			cin>>x;
			minimum = min(minimum, x);
			maximum = max(maximum, x);
		}
		int minSum = INT_MAX;
		for(int i=minimum; i<=maximum; i++){
			int tempSum = 0;
			for(int j=0; j<3; j++){
				tempSum += abs(i - nums[j]);
			}
			minSum = min(minSum, tempSum);
		}
		cout<<minSum<<endl;
	}

	return 0;
}


