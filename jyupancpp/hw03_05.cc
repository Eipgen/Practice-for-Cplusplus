#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int fact(int x)
{
    int i,f=1;
    for (i=1;i<=x;i++)
        f*=i;
    return f;
}

int main(){
    int n,i;
    //long double s=pow(10,14);
    double s=1;
    //double s=0;
    
    cout <<"Please input a integer:";
    cin >>n;
 
    //cout << fact(n)<<endl;
    
    for(i=1;i<=n;i++){
        s=s+1.0/fact(i);
    }
    cout.setf(ios::fixed,ios::floatfield);
    cout <<  setprecision(6) << " e is " << s <<endl;
    return 0;
}
