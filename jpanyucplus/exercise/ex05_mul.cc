#include <iostream>
#include <cmath>
#include <cmath>
using namespace std;

const int n=3;
int main()
{
    clock_t start,end;
    int i,j,k;
    int C[][],A[][],B[][];
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            for (k=0;k<n;k++)
                C[i,j]=C[i,j]+A[i][k]*B[i][k];
    
    }