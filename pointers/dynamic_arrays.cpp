#include <iostream>

using namespace std;

int main(){
	int a;
	void *x = &a;
	cout<<&a<<endl;
	(int*)x;
	cout<<&a<<endl;
	cout<<(int*)x++;
	return 0;
}