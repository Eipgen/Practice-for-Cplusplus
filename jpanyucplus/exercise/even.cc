#include <iostream>
using namespace std;

int main(){
    int n=0;
    cout << "input a number:";

    cin >>n;
    if (n % 7==0){
        cout <<"can be mod by 7 test ";
    } else{
        cout << "no";
    }
    return 0;
}
