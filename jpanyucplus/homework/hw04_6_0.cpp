#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

bool prime(long long int x)
{
    if (x%2==0)
        return x=2;
    for(long long int i=3;i<=sqrt(x);i=i+2)
    {
        if((x%i)==0)
            return false;
    }
    return true;
}

int lucas_lehmer(long long int n)
{
    long long int a=4;
    long long int m=pow(2,n)-1;
    for(long long int i=0;i<n-2;i++)
    {
        a=((a*a)-2)%m;
        //cout << a << endl;
    }
    if (a==0)
        return true;
}

int main()
{
    long long int m;
    for (long long int i=3;i<64;i=i+1)
    {
        m=pow(2,i)-1;
        if (lucas_lehmer(i)==true)
            cout << i << " " << m << endl; 
        //if (prime(i)==true && lucas_lehmer(i)==true)
        //    cout << i <<" " <<m << endl;
    } 

}