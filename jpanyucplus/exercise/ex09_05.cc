#include <iostream>
#include <cstdlib>
using namespace std;

const float pi = 3.1415927;
const float price1 = 35.0;
const float price2 = 20.0;

class Circle
{
    public:
        Circle(float x){r=x;}
        float Area();
        float Circum();
    private:
        float r;
};

float Circle::Area()
{
    return pi * r * r;
}

float Circle::Circum()
{
    return 2 * pi * r;
}

int main()
{
    float x,y,z;
    cout << "Please input the radius of the circle: ";
    cin >> x;
    Circle Pool(x);
    Circle PoolRim(x+3);

    y =PoolRim.Circum()*price1;
    cout << "The price of the pool is: " << y << endl;

    z = (PoolRim.Area()-Pool.Area())*price2;
    cout << "The price of the pool rim is: " << z << endl;

    return 0;
}