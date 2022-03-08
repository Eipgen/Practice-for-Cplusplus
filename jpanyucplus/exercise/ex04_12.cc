#include <iostream>
using namespace std;


int factorial_loop(int n);
int factorial_recursion(int n);


int main()
{
    int n,y;
    cout << "input n: ";
    cin >>n;

    y = factorial_loop(n);
    cout << "normal mode: " << n << "!=" << y << endl;
    y = factorial_recursion(n);
    cout << "recursion mode: " << n << "!=" <<y << endl;
    return 0;
}

int factorial_loop(int n)
{
    int y = 1;

    for (int i=1;i<=n;i++)
        y=y*i;
        return y;
}

int factorial_recursion(int n)
{
    if (n==0)
        return 1;
    else
        return n*factorial_recursion(n-1);
}
