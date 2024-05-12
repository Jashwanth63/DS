#include <iostream>
using namespace std;

int main(){
	int arr[100][100];
	int r, c, k;
	cin>>k>>r>>c;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>arr[i][j];
		}
	}
	int i=0, j=c-1;
	while(j>=0 and i<=r-1){
		int number = arr[i][j];
		if(number > k){
			j--;
			continue;
		}
		else if(number < k){
			i++;
			continue;
		}

		else if(number == k){
			cout<<"Number Found"<<endl;
			break;
		}
	}
	if(j<0 || i>r-1){
		cout<<"Number Not Found"<<endl;
	}

	return 0;
}