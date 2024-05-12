#include <iostream>
#include <vector>

using namespace std;



int partition(vector<int> &arr, int start, int end){
	int element = arr[end];
	int i=start-1;
	int j=start;
	while(j<=end){
		if(arr[j]<=element){
			i++;
			swap(arr[i], arr[j]);
		}
		j++;
	}
	return i;
}

void quickSort(vector<int> &arr, int start, int end){
	if(start>=end){
		return;
	}
	int p = partition(arr, start, end);

	quickSort(arr, start, p-1);
	quickSort(arr, p+1, end);

}



int main(){
	vector<int> arr{5,4,3,2,1};
	quickSort(arr, 0, arr.size()-1);
	for(int element: arr){
		cout<<element<<" ";
	}

	return 0;
}