#include <iostream>
using namespace std;

void zero_out_array(int *arr, int n);
int a[10] = {1,2,3,5,4,6,7,8,9,10};

int main() 
{
    int *p;
    //int a[10] = {1,2,3,5,4,6,7,8,9,10};
    p = a;
    zero_out_array(a,10);
    for (int i=0;i<10;++i){
        cout << *(p+i) << " ";
    }
    return 0;
}

void zero_out_array(int *p, int n)
{
    while (n-- >0)
    {
        *p = 0;
        ++p;
    }
}
