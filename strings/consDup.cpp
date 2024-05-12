#include <iostream>

using namespace std;

char remove_dup(char a[]){
	int i=0;
	int j=1;
	while(a[j] != '\0'){
		if(a[i] == a[j]){
			++j;

		}	
		else {
			++i;
			a[i] = a[j];
			++j; 
		}
	}
	a[++i] = '\0';
	
	
}

int main(){
	char a[100];
	cin>>a;
	remove_dup(a);
	cout<<a;
	return 0;
}