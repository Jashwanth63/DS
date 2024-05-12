#include <iostream>

using namespace std;

int main(){
	int arr[10] = {0};
	int n = sizeof(arr)/sizeof(int);
	/*
	cout<<"Size of Arr is : "<<sizeof(arr)<<endl;
	cout<<"Size of int is: "<<sizeof(int)<<endl;
	cout<<"N: "<<n<<endl;
	*/
	for(int i=0; i<n; i++){
		arr[i] = i*2;
	}

	int element, flag=0;
	cout<<"Enter the Element to search: ";
	cin>>element;
	for(int i=0;i<n;i++){
		if(element == arr[i]){
			flag = 1;
			cout<<endl<<"Element found at position "<<i+1;
			break;
		}
	}
	if(flag == 0){
		cout<<endl<<"Element Not found in Array";
	}
	return 0;

}