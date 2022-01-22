#include <iostream>
using namespace std;

void swap_old(int a, int b)
{
    int t = a ;
    a = b;
    b = t;
}

void swap_new(int & a,int &b)
{
    int t=a;
    a=b;
    b=t;
}

int main()
{
    int x=5,y=8;
    cout << "before swap: x=" << x << ",y= " << y << endl;
    swap_old(x,y);
    cout << "after swap_old: x=" << x << ",y= " << y << endl;
    swap_new(x,y);
    cout << "after swap_new: x=" << x << ",y= " << y << endl;
    return 0;

}
