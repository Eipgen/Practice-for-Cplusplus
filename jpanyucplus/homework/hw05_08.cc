#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void dec2binmatrix(int n,int A[M][M])
{
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<M;j++)
            A[i][j]=0;
}
