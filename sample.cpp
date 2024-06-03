#include <set>
#include <iostream>

using namespace std;

int main(){

    set<int> nums;
    int arr[7] = {1,22,2,3,4,6,6};
    for(int i=0; i<7; i++){
        nums.insert(arr[i]);
    }
    for(auto i: nums){
        cout<<i<<" "    ;
    }
    cout<<*nums.begin()+2;
    return 0;
}