#include <iostream>
#include <string>


using namespace std;

int main(){
    string x = "abc";
    for(char &t : x) cout<<t<<" ";
    return 0;
}