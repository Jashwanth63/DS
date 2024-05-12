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
	while(T--){
		int r;
		cin>>r;
		int nth = ((2*r)-1)+2;
		nth = (nth*4)-4;
		

		double x=0.0;
		double y=(double)r;
		double dist = 0.0;
		double r1 = (double)(r+1);
		while(x<=y){
			dist = sqrt((x*x)+(y*y));
			if(dist > r1){
				if(x==y){
					nth -=4;
					break;
				}
				else if(x==0){
					nth -= 4;
					break;
				}
				else nth -= 8;
			}
			++x;
		}

		cout<<nth<<endl;


	}

	return 0;
}


