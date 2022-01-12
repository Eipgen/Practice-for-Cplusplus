#include <iostream>
#include <cmath>
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

int reverse(int x)
{
    int num=0;
    while (x>0);
    {
        num = (num*10)+x%10
        x=x/10
    }
    return x;
}


int main()
{
    int m,n;
    cout << "input number:";
    cin >>m>>n;
    int num=0;
    for (int x=m;x<=n;x++)
    {
        if (prime(x)==true && prime(reverse(x))==true)
        {
            num++;
            cout << x << " ";
            if (num % 8==0)
            {
                cout << endl;
            }
        }
    }
    return 0;
}
