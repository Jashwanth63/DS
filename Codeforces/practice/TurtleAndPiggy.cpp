#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int a, b;
		cin>>a>>b;
		// Find Closest power of two
		int base = (int)log2(b);
		cout<<base<<endl;
	}
}