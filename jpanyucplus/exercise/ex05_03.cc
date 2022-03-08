#include <iostream>
#include <cmath>
#include <cmath>
using namespace std;

void my_swap(int a[], int b[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        int temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}

int main()
{
    const int n=3;
    int i;
    int x[n]={1,2,3},y[n]={4,5,6};
    for (i=0;i<n;i++)
    {
        cout << "x["<< i <<"]=" << x[i] << "\t"
        << "y["<< i <<"]=" << y[i]<<endl;
    }
    my_swap(x,y,n);
    for (i=0;i<n;i++)
    {
        cout << "x["<< i <<"]=" << x[i] << "\t"
        << "y["<< i <<"]=" << y[i]<<endl;
    }
    cout << endl;
    return 0;
}