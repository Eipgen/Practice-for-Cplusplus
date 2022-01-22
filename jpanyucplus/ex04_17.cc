#include <iostream>
using namespace std;

int k;

int main()
{
    int x=5;
    cout << "k=" << k << endl;
    int my_plus(int x);

    cout << "x+i=" << my_plus(x) << endl;
    cout << "x+i=" << my_plus(x) << endl;

    return 0;
}

int my_plus(int x)
{
    static int i=5;
    i=x+i;
    return i;

}
