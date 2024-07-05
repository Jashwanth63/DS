#include <set>
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>

typedef unsigned long long ll;
using namespace std;



string findClosest(ll &original, string n, int i, int len) {
    if(i >= len) return n;
    string ans;
    int current = n[i] - '0';
    if(current %2 != 0){
        ans = findClosest(original, n, i+1, len);
    }
    else{
        // Check for +1 and -1
        current = current+1;

        n[i] = static_cast<char>(current + '0');
        string temp1 = findClosest(original, n, i+1, len);
        current = current-2;
        n[i] = static_cast<char>(current + '0');
        
        string temp2 = findClosest(original, n, i+1, len);

        ll calc1 = stoull(temp1, nullptr, 10);
        ll calc2 = stoull(temp2, nullptr, 10);
        if(abs(original - calc1) > abs(original - calc2)){
            ans = temp2;
        }
        else if(abs(original - calc1) < abs(original - calc2)){
            ans = temp1;
        }
        else{
            ans = to_string(min(calc1, calc2));
        }
    }
    return ans;
}


int main(){
    ll num;
    cin>>num;
    string n= to_string(num);
    int len = n.length();
    // cout<<stoull(num, nullptr, 10);
    //cout<<'9' - '0'<<endl;
    string temp = findClosest(num, n, 0, len);
    cout<<stoull(temp, nullptr, 10);
    return 0;
}