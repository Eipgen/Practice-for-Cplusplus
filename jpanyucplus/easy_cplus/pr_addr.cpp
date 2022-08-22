#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int a=2,b=3,c=4;
    int *pa = &a;
    int *pb = &b;
    int *pc = &c;
    cout << "pointer a is " << pa << endl;
    cout << "pointer b is " << pb << endl;
    cout << "pointer c is " << pc << endl;
    cout << a <<" "<< b <<" "<< c << endl;
    return 0;
}

