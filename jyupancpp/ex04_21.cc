#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int n = 1000000;
const double r = 1.0;

int main()
{
    double x,y;
    int m=0;

    srand(time(0));
    for(int i=1;i<n;i++)
    {
        x = r*double(rand())/RAND_MAX;
        y = r*double(rand())/RAND_MAX;
        if (x*x+y*y <r*r)
            m++;
    }
    cout << "pi is " << 4*m/double(n) << endl;

    return 0;
}

