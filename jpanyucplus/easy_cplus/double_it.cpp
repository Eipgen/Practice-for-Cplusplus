#include <iostream>
using namespace std;

void double_it(int *p);

int main()
{
    int a = 5,b = 6;
    cout << "before a " << a << endl;
    cout << "before b " << b << endl;

    double_it(&a);
    double_it(&b);
    
    cout << "after a " << a << endl;
    cout << "after b " << b << endl;

    return 0;
}

void double_it(int *p)
{
    *p = *p * 2;
}