#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N=5;
    int* pa = new int[N](); // all array value is 0
    int* pb = new int[N]{1,2,3,4,5}; // array value is 1,2,3,4,5
    // create the one-dim array 

    // px =new [n1][n2]...[nm] 
    // build multiple array
        
    for(int i=0; i<N; i++)
        cout << *(pa+i) << " ";
    cout << endl << endl;

    for(int i=0; i<N; i++)
        cout << *(pb+i) << " ";
    cout << endl;

    delete[] pa;
    // free the array
    delete[] pb;
    return 0;
}