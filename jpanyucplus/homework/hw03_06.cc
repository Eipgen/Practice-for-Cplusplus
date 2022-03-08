#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;


int main(){
    int i,num=0;
    for(i=2001;i<=2099;i++){
        if((i%4==0&&i%100!=0)||(i%400==0)){
            num++;
            cout << i << " ";
            if (num % 6==0){
            cout << endl;
            }
        }
    }
    return 0;
}
