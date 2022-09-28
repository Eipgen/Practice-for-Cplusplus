#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
    public:
        Point(int a=0, int b=0)
        {
            x = a;
            y = b;
        }
        Point(const Point &);
        int Getx()
        {
            return x;
        }
    private:
        int x,y;
};

Point::Point(const Point & p)
{
    x = p.x;
    y = p.y;
    cout << "self define constructor is used! " << endl;
}

void f(Point p)
{
    cout << "x = " << p.Getx() << endl;
}

Point g()
{
    Point a(4,5);
    return a;
}

int main()
{
    Point a(1,2);
    cout << " Point b(a)";
    Point b(a);
    cout << "x = " << b.Getx() << endl << endl;
    
    cout << "f(b)";
    f(b);
    cout << endl;

    cout << "c = a: ";
    Point c;
    c = a;
    cout << "x = " << c.Getx() << endl << endl;

    cout << "C=g(): ";
    c = g();
    cout << "x = " << c.Getx() << endl << endl;
    return 0;
}
