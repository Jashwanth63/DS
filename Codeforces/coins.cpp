#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int count = 0;
		int n, m, k;
		cin>>n>>m>>k;
		vector<int> narr(n, 0);
		vector<int> marr(m, 0);

		for(int i=0; i<n; i++){
			cin>>narr[i];
		}
		for (int i=0; i<m; i++){
			cin>>marr[i];
		}

		sort(narr.begin(), narr.end());
		sort(marr.begin(), marr.end());

		for(int i=0; i<n; i++){
			for(int j=m-1; j>=0; j--){
				if((narr[i] + marr[j])<=k){
					count += j+1;
					break;
				}
			}
		
		}
		cout<<count<<endl;
	}

	return 0;
}