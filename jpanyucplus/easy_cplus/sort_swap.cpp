#include <iostream>
using namespace std;

void sort(int n);
void swap(double *p1, double *p2);

double a[10];

int main()
{
    for (int i=0;i<10;i++)
    {
        cout << "enter number "<<i<<":";
        cin >>a[i];
    }
    sort(10);

    cout << "sorted array" << endl;
    for (int i=0;i<10;i++)
    {
        cout << a[i] <<" ";
    }
    return 0;
}

void sort(double a[], int n)
{
    for (int i=n-1;i>0;i--)
    {
        for (int j=0;j<i;j++)
        {
            if (a[j] > a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }    
}


void swap(double *p1, double *p2)
{
    double temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
