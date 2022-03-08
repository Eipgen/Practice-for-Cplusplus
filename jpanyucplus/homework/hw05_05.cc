#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int findminindex(int x[],int n)
{
    int i;
    int min=x[0];
    int minindex=0;
    for (i=1;i<n;i++)
        if (x[i]<min)
        {
            min=x[i];
            minindex=i;
        }
    return minindex;
}

int main()
{
    int x[]={12, 29, 34, 56, 59, 72, 85, 88, 91, 93};
    int m;
    m=sizeof(x)/sizeof(x[0]);
    cout << "min=" << x[findminindex(x,m)] << ",minindex="<< findminindex(x,m) << endl;
    return 0;
}