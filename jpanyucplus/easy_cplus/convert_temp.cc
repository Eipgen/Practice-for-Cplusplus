#include <iostream>
using namespace std;

void convert_temp(float *p)
{
    *p = (*p * 1.8)+32;
}


int main()
{
    float temp;
    cout << "input the temperature: ";
    cin >>temp;

    cout << "Before Celsius " << temp << endl;
    
    convert_temp(&temp);
    
    cout << "After F " << temp << endl;
    return 0;
}

void double_it(int *p)
{
    *p = *p * 2;
}