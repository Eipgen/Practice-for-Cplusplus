#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

int num_chain(int x)
{
    int count=0;
    while(x!=1){
        cout << x << " ";
        if(x%2==0)
            x=x/2;
        else
            x=3*x+1;
        count++;
    }
    //cout <<"num_chain: " << count+1 << endl;
    return count+1;
}

int main()
{
    int m;
    //cout << "Please input a number: ";
    //cin >> m;
    for (int i=90;i<=100;i++)
    cout << i << " " << num_chain(m) << endl;
}