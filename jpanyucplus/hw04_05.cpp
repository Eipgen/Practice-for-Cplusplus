#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;

bool is_leap_year(int x)
{
    if (x%4==0&&x%100!=0 || (x%400==0))
        return true;
    else
        return false;
}



int main(){
    int num=0;
    for(int i=2001;i<=2099;i++){
        if(is_leap_year(i)==true){
            num++;
            cout << i << " ";
            if (num % 6==0){
            cout << endl;
            }
        }
    }
    return 0;
}
