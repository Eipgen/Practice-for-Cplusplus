#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

const int N=5;

void matrix_product(int X[N][N],int Y[N][N],int Z[N][N])
{
    int i,j,k;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
        {
            Z[i][j]=0;
            for (k=0;k<N;k++)
                Z[i][j]+=X[i][k]*Y[k][j];
        }
}

int RandomMatrix(int X[N][N])
{
    int i,j;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
            X[i][j]=rand()%9;
}

int main()
{
    int X[N][N],Y[N][N],Z[N][N];
    int i,j;
    RandomMatrix(X);
    RandomMatrix(Y);
    matrix_product(X,Y,Z);
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
            cout << X[i][j] << " ";
        cout << endl;
    }
    cout << "*" << endl;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
            cout << Y[i][j] << " ";
        cout << endl;
    }
    cout << "=" << endl;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
            cout << Z[i][j] << " ";
        cout << endl;
    }
    return 0;
}