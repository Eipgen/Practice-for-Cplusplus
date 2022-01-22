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

    while (x>0)
    {
        num = (num*10)+x%10;
        x=x/10;
    }
    return num;
}


int main()
{
    //int m,n;
    //cout << "input number:";
    //cin >>m>>n;
    int y;
    int num=0;
    for (int x=0;x<=10000;x++)
    {
        //cout << reverse(x) << endl;
        if (prime(x)==true && prime(reverse(x))==true)
        {
            num++;
            cout << "x=" << x <<" R_x= " << reverse(x)<<endl;
            if (num==100)
                break;
        }
    }
    return 0;
}
