#include <iostream>
#include <cmath>
#include <cmath>
using namespace std;

const int n=1000;

int main()
{
    clock_t start,end;
    int i,j;
    double H[n][n],x[n],y[n];

    start=clock();
    for (i=0;i<n;i++)
    {
        x[i]=1.0;
        y[0]=0.0;
    }

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            H[i][j]=1.0/(i+j+1);
        }
    }

    for (i=n-1;i>=0;i--)
    {
        for (j=n-1;j>=0;j--)
        {
            y[i]+=H[i][j]*x[j];
        }
    }
    end=clock();
    cout << "y[0]=" << y[0] <<",y[n-1]=" << y[n-1]<< endl;
    cout << "time=" << (double)(end-start)/CLOCKS_PER_SEC << endl;
    cout << endl;
    cout << "x[0]=" << x[0] <<",x[n-1]=" << x[n-1]<< endl;
    cout << "H[0][0]=" << H[0][0] <<",H[n-1]H[n-1]=" << H[n-1][n-1]<< endl;
    return 0;
}