#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;


int insert(int x[],int n,int k)
{
    int i;
    for (i=0;i<n;i++)
        if (x[i]>k)
            break;
    x[i]=k;
    return n+1;
}




int main()
{
    int x[]={12, 29, 34, 56, 59, 72, 85, 88, 91, 93};
    int m;
    int s=90;
    m=sizeof(x)/sizeof(x[0]);
    //cout << "m=" << m << endl;
    //cout << insert(x,m,s) << endl;
    insert(x,m,s);
    for (int i=0;i<m;i++)
        cout << x[i] << " ";
    //return 0;
}