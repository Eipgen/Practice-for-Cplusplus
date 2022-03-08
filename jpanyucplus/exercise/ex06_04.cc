#include <iostream>
using namespace std;

/*
the secondary pointer
int a=2;
int *pa = &a;
int **ppa = &pa;
*/


int main()
{
    const int m=3,n=4;
    int a=3;
    int *pa = &a,**ppa = &pa;

    cout << "a = " << a << endl;
    cout << "a = " << *pa << endl;
    cout << "a = " << *(*ppa) << endl;

    cout << endl;
    
}