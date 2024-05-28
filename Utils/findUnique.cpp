#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
	vector<int> nums{1,1,1,2,2,3,3,4,5,6}; // Has to be sorted;
	sort(nums.begin(), nums.end());
	unordered_map<int, int> uniqueIndices;
	int len = nums.size();
	for(int i=0; i<len; i++){
		if(uniqueIndices.find(nums[i]) == uniqueIndices.end()){ //If number Doesn't exist
			uniqueIndices[nums[i]] = i;
		}
	}

	//cout<<uniqueIndices.size();
	cout<<uniqueIndices[12];

	return 0;
}  