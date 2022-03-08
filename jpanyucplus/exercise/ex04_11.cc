#include <iostream>
#include <ctime>
using namespace std;

inline double f(double x) // inline functio
{
    return 2*x*x-1;
}

int main()
{
    cout << "f(3)=" << f(3.0) << endl;
    return 0;
}

