#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a{1,2,3,0,0,0};
    int len = a.size();
    int m=3;

    int k=1;
    a.insert(a.begin()+k, 5);

    for(int i: a){
        cout<<i<<" ";
    }

    return 0;
}