#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

int fibonacci(int n)
{
    if(n <=2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
    //int m;
    //cout << "Please input a number: ";
    //cin >> m;
    
    for (int i = 0; i < 41; i++)
    {
        cout << setw(4) << fibonacci(i) << endl;
    }
    //pwcout << m << " " << fibonacci(m) << endl;
}
 