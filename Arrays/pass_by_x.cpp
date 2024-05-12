#include <iostream>
using namespace std;

void swapp(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	int a = 1, b= 2;
	swapp(a, b);
	cout<<a<<" "<<b;

	return 0;
}