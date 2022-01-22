#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int n = 100000;
const double a = 0.0;
const double b = atan(1)*2;
const double length = b-a;

int main()
{
    long double S = 0.0;
    double x;
    srand(time(0));
    for(int i=1;i<=n;i++)
    {
        x = a + length*double(rand())/RAND_MAX;
        S = sin(x);
    }
    cout << "S=" << length/n*S <<endl;
    return 0;
}
