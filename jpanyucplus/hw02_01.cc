#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double radius,height,pi=3.14;
    cout << "input radius :";
    cin >> radius;
    cout << "input height :";
    cin >> height;

    double volume = (radius*radius)*height*pi;
    cout << "volume is " << volume <<endl ;
    return 0;
}
