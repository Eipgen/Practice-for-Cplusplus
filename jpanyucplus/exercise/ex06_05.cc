#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int Gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return Gcd(b,a%b);
}
int Lcm(int a, int b)
{
    return a*b/Gcd(a,b);
}

int main()
{
    int a,b;
    int (* pf)(int, int);
    cout << "Input a and b: ";
    cin >>a>>b;

    pf = Gcd;
    cout << "greast common number: " << pf(a,b) << endl;
    pf = Lcm;
    cout << "lowest common number:" << pf(a,b) << endl;
    return 0;
}