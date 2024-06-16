#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

bool doBackTrack(ll x, int carry){
	if(x==0 && carry!=0) return true;
	int lastDigit = x%10 + carry;
	x = x/10;
	for(int i=lastDigit+1; i<=9; i++){
		int temp = (lastDigit+10)-i;
		cout<<temp<<" ";
		carry = (i + lastDigit)>=10 ? 1:0;
		if(temp>=5 && temp<=9) doBackTrack(x, carry);
		cout<<endl;
	}
	return false;
}


typedef long long ll;
int main(){
	int T;
	cin>>T;
	while(T--){
		ll x;
		cin>>x;

		//Take Mod and Divide
		if(doBackTrack(x, 0)) cout<<"YES";
		else cout<<"NO";
		cout<<endl;


	}
	return 0;
}