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
		int n, m;
		cin>>n>>m;
		vector<int> indices(m, 0);
		string s;
		cin>>s;
		for(auto &x: indices){
			cin>>x;
		}
		sort(indices.begin(), indices.end());
		string c;
		cin>>c;
		sort(c.begin(), c.end());
		unordered_map<int, char> assigned_min;
		int j=0;
		for(int i=0; i<m; i++){
			if(assigned_min.find(indices[i]-1) == assigned_min.end()){
				s[indices[i]-1] = c[j];
				assigned_min[indices[i]-1] = c[j];
				j++;
			}
			
			
		}
		cout<<s<<endl;
	}

	return 0;
}


