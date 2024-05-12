#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		
		int n;
		cin>>n;
		vector<int> arr(n, 0);
		vector<int> pos;

		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		


		auto ma = max_element(arr.begin(), arr.end());

		while (ma != arr.end()){

			pos.push_back(distance(arr.begin(), ma));
        	ma = find(next(ma), arr.end(), *ma);

			cout<<*(pos.end());
			
		}
		
		cout<<endl;
	}

	return 0;
}