#include <iostream>
using namespace std;

void sort(int n);
void swap(int *p1, int *p2);

int a[10];

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

void sort(int n)
{
    int low = 0;
    for (int i=0;i<10;i++)
    {
        low=i;
        for (int j=i+1;j<n;++j)
        {
            if (a[j] < a[low])
            {
                low = j;
            }
        }
        if (i != low)
        {
            swap(&a[i],&a[low]);
        }
    }
}


void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
