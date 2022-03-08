#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

/* row pointer 
int A[3][4]
int (*pa)[4] = A;
...
for(int i=0; i<m; i++)
{
    for(int j=0; j<n; j++)
    {
        cout << setw(3) << *(*(pa+i)+j);
    }
    cout << endl;
}
*/

int main()
{
    const int m=3,n=4;
    int A[m][n]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int (*pa)[n] = A;

    cout << "row pointer A: " << endl;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << setw(3) << *(*(pa+i)+j);
        }
        cout << endl;
    }

    cout << "using pointer to access array A: " << endl;
    int *pa2[m] ={A[0],A[1],A[2]};
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << setw(3) << *(*(pa2+i)+j);
        }
        cout << endl;
    }
    cout << endl;

}