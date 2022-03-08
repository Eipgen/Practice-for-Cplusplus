#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int n = 5;
int main()
{
    int A[n][n];
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A[i][j] = i+j;
        }
    }
    cout << "array A: " << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << setw(3) <<A[i][j];
        }
        cout << endl;
    }

    cout << "using pointer to access array A: " << endl;
    int *pa = &A[0][0];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << setw(3) << *(pa+i*n+j);
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

/*
*A[0]=A[0][0]


pa = &A[0][0];
A[i][j] = *(pa+i*n+j);
*/