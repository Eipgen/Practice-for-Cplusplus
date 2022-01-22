#include <iostream>
using namespace std;

int i=2;

int main()
{
    int i=5;
    {
        int i=7;
        cout << "i=" <<i<<endl;
    }
    cout << "i=" <<i << endl;
    cout << "global variable i=" << ::i <<endl;
}
