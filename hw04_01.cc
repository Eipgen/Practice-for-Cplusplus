#include <iostream>
using namespace std;

int gcd(int x,int y)
{
    if (x%y==0)
        return y;
    else
    {
        gcd(y,x%y);
    }
}

int lcm(int x,int y)
{
    return x*y/gcd(x,y);
}

int main()
{
    int m,n;
    cout << "input number:";
    cin >>m>>n;
    cout << "gcd number is " << gcd(m,n) <<endl;
    cout << "lcm number is " << lcm(m,n) <<endl;
    return 0;
}
