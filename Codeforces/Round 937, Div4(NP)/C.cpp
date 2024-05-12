#include <iostream>
#include <string>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		string hour = strcat(s[0],s[1]);
		int thc = stoi(hour) - 12;
		if(thc>=0){
			if(thc>=10) cout<<to_string(thc) + ":" + s[3] + s[4] + " " + "PM";
			else cout<<"0" + to_string(thc) + ":" + s[3] + s[4] + " " + "PM";
		}
		else{
			if(thc == -12){
				cout<<to_string(12) + ":" + s[3] + s[4] + " " + "AM";
			}
			else cout<<s + " AM";
		}

	}
	string s = "09";
	cout<<stoi(s);

	return 0;
}