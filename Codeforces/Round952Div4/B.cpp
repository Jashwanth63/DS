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
		int sum = 0;
		int maxSum = INT_MIN;
		pair<int, int> maxPair(0, -1); // First is maxSum, second is the integer with the maxSum
		cin>>n;
		for(int i=2; i<=n; i++){
			for(int j=1; (j*i)<=n; j++){
				sum += (j*i);
			}
			maxPair.first = maxPair.first <= sum ? sum : maxPair.first;
			maxPair.second = maxPair.first <= sum ? i : maxPair.second;
			sum = 0;
		}
		cout<<maxPair.second<<endl;
		
	}

	return 0;
}


