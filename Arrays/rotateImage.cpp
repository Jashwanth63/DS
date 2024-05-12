#include <iostream>
using namespace std;

int main(){
	int arr[100][100];
	int r, c;
	cin>>r>>c;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>arr[i][j];
		}
	}

	//Rotate Image
	for(int i=c-1; i>=0; i--){
		for(int j=0; j<r; j++){
			cout<<arr[j][i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}