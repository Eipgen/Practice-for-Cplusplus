#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
    int seed,x;
    cout << "enter seed: ";
    cin >> seed;
    srand(seed);
    x = rand();

    cout << "x= " << x << endl;
    cout << "seed= " << seed << ", RAND_MAX " << RAND_MAX << endl;
    
    for(int i=0;i<10;i++)
    {
        x = rand();
        cout << "i=" << i << ",x=" << x << endl;
    }
    return 0;
}
