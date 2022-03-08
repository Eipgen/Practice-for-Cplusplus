#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

bool prime(int x)
{
    if (x<2)
        return false;
    for(int i=2;i<=sqrt(x);i++)
    {
        if((x%i)==0)
            return false;
    }
    return true;
}

int main()
{
    int m;
    for (int i=2;i<32;i++)
    {
        m=pow(2,i)-1;
        if (prime(m)==true)
        {
            cout << i << " "<<m<<endl;
        }
    } 

}