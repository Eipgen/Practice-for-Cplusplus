#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

int num_chain(int x)
{
    int count=0;
    if(x==1)
        return 1;
    else
    {
        cout << x << " ";
        if(x%2==0)
            x=x/2;
        else
            x=3*x+1;
        count++;
        return count+num_chain(x);
    }
}

int main()
{
    int m;
    cout << "Please input a number: ";
    cin >> m;
    //for (int i=90;i<=100;i++)
    cout << m << " " << num_chain(m) << endl;
}