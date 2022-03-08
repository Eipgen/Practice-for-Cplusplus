#include <iostream>
#include <cmath>

using namespace std;

double mysin(double x)
{
    double s,te;
    int k;
    s = 0.0;
    k = 1;
    te = x;

    while (abs(te) >=1e-30)
    {
        s = s+te;
        te = -te*x*x/(2*k*(2*k+1));
        k=k+1;
    }
    return s;
}

int main()
{
    double x,y;
    cout << "input x: ";
    cin >> x;
    y = mysin(x);
    cout << "mysin(x) is " << y << endl;
    cout << "built-in-func " << sin(x) << endl;
    return 0;
}
