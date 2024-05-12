#include <iostream>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int a, b, c;
		cin>>a>>b>>c;
		if(a<b && b<c){
			cout<<"STAIR";
		}
		else if(a<b && b>c){
			cout<<"PEAK";
		}
		else{
			cout<<"NONE";
		}
		cout<<endl;
	}

	return 0;
}