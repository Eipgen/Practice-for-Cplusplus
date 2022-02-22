/*
#include <stdio.h>
#define NDOORS 100

int main() 
{
    int doors[NDOORS] ={0};
    for (int j=1;j<=NDOORS;j++)
    {
        for (int i=j-1;i<NDOORS;i++)
        {
            doors[i]=1-doors[i];
        }
    }
    for (int c=0;c<NDOORS;c++)
    {
            if (doors[c]==1)
        {
        printf("%d ",c+1); 
        }
    }
    return 0;
}
*/

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int* boolbox(int x[100])
{
    int x[100]={0};
    for (int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            x[i]=1-x[i];
    return x;
}

int main()
{
    int x[100]={0};
    for (int c=0;c<100;c++)
    {
        int *B=boolbox(x);
        if (B[c]==1)
            cout << c+1 << " ";
    }
    return 0;
}