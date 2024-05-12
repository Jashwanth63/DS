# include <iostream>
# include <queue>

using namespace std;

int main(){
	priority_queue<int, vector<int>, greater<int>> pq;
	int arr[5] = {3,1,10,10,1};
	int arr2[5] = {4,8,2,2,7};

	double ans = 0.0;
	for(int i=0; i<5; i++){
		cout<<(double)arr[i]/arr2[i]<<" ";
	}

	return 0;
}