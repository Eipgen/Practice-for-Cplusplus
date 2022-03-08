#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;

const int n=100000;
const double a=0.0;
const double b=atan(1)*2;
const double l=b-a;

int main()
{
    long double S=0.0;
    double x;

    srand(time(0));
    for(int i=0;i<n;i++)
    {
        x=a+l*rand()/RAND_MAX;
        S+=sin(x);
    }
    cout << "S=" << setprecision(10)<< l/n*S << endl;
    return 0;
}
