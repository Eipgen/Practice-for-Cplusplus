#include <iostream>
#include <cmath>
using namespace std;

int bin2dec(long m)
{
    int y=0,k=0;
    while (m !=0)
        {
            y = y + (m%10)*pow(2,k);
            m= m/10;
            k=k+1;
        }
    return y;
}

int main()
{
    long m;
    cout << "input m : ";
    cin >>m;

    cout << "binary "<<m << " become " << bin2dec(m) << endl;
    return 0;
}
