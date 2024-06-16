#include <iostream>
#include <climits>
#include <string>
#include <vector>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int> arr(n, 0);
		int minimum = INT_MAX;
		int maximum = INT_MIN;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			minimum = min(minimum, arr[i]);
			maximum = max(maximum, arr[i]);
		}
		if(minimum == maximum){
			cout<<"NO"<<endl;
			continue;	
		} 
		string s(n, 'R');
		//cout<<s<<" ";
		int indexToChange = -1;
		for(int i=1; i<n; i++){
			if(arr[i-1] == arr[i]){
				indexToChange = i;
				break; 	
			} 
		}
		if(indexToChange == -1) s[0] = 'B';
		else s[indexToChange] = 'B';
		cout<<"YES"<<endl<<s<<endl;

	}
	return 0;
} 