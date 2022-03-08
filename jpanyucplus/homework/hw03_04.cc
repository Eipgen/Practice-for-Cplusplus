#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int n,i;
    //long double s=pow(10,14);
    double s=pow(10,14);
    //double s=0;
    
    cout <<"Please input a integer:";
    cin >>n;
 
    for(i=1;i<=n;i++){
        
        s=s+1.0/i;
    }
    cout.setf(ios::fixed,ios::floatfield);
    cout <<  setprecision(6) << " left to right " << s <<endl;

    int j;
    //long double t=0;
    double t=0;
    
    for(j=n;j>=1;j--){
        
        t=t+1.0/j;
    }
    cout.setf(ios::fixed,ios::floatfield);
    cout <<  setprecision(6) << " right to left " << t + pow(10,14) <<endl;



    return 0;
}
