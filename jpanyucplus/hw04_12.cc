#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

int mylog(int n=2)
{
    int m;
    cout << "Please input y: ";
    cin >> m;
    if (m>0)
    {
        cout << log(m)/log(n) << endl;
    }
    else
    {
        cout << "Please input a positive number!" << endl;
    }
}
int main(){
	double value;
    cout << "Please input x:";
    if (cin >>value)
    {
        cout << mylog(value) << endl;
    }
    else if (cin.get=='\n')
        cout << mylog() << endl;
    return 0;
}