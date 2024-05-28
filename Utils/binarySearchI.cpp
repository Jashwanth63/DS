#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> nums{1,5,7,7,7,7,12,12};
	sort(nums.begin(), nums.end());
	// Want to find the number thats immediately greater than the one I'm looking for

	int s = 0;
	int e = nums.size() - 1;

	int x = 10;
	int mid;
	while(s<=e){
		mid = s + (e - s) / 2;

		if(nums[mid] == x){
			e = mid-1;
		}

		else if(nums[mid] < x) {
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	cout<<s<<" "; 

	return 0;
}