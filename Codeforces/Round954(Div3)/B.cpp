#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <string>
#include <cmath>
#include <algorithm>



typedef long long ll;
typedef long l;

using namespace std;




int main(){
	int T;
	cin>>T;
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	while(T--){
		int rows, cols;
		cin>>rows>>cols; 
		vector<vector<int>> matrix(rows, vector<int>(cols, 0));
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				cin>>matrix[i][j];
			}
		}
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){	
				int minCurr = INT_MIN;
				int curr = matrix[i][j];
				bool strict = true;
				for(int k=0; k<4; k++){
					int newi = i+dx[k];
					int newj = j+dy[k];
					if(newi<0 || newi>=rows || newj<0 || newj >= cols) continue;
					int temp = matrix[newi][newj];
					if(temp >= curr){
						strict = false;
						break;
					}
					minCurr = max(minCurr, temp);
				}
				if(strict) matrix[i][j] = minCurr;
			}
		}


		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}


