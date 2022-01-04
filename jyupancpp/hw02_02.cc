#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double frate,srate,mon=100;
    cout << "frate :";
    cin >> frate;
    double montot1=mon*pow(1+frate,5);
    cout << "first end mon:" <<montot1 <<endl;
    
    cout << "srate :";
    cin >> srate;
    double montot2=mon+mon*srate*5;
    cout << "second end mon:" <<montot2<<endl;

    return 0;
}
