#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int> nums(n, 0);
		long ans;
		int big = INT_MIN;
		for(int &x: nums){
			cin>>x;
			big = max(x, big);
		}
		cout<<(long)big+1<<endl;

	}
	return 0;
}
