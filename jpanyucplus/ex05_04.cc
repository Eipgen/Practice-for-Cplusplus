#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;

const int m=3,n=4; // define the matrix 

void sum_col(double A[][n],double s[])
{
    int i,j;
    for(j=0;j<n;j++)
        s[j]=0.0;
    
    for(j=0;j<n;j++)
        for(i=0;i<m;i++)
            s[j]+=A[i][j];
}

int main()
{
    int i,j;
    double H[m][n],s[n];

    for (i=0;i<m;i++)
        for (j=0;j<n;j++)
            H[i][j]=1.0/(i+j+1); // Hilber matrix
    sum_col(H,s);

    cout << "H[0][0]=" << H[0][0] << ",H[0][n-1]=" << H[0][n-1] <<endl;
    cout << "s[0]=" << s[0] << ",s[n-1]=" << s[n-1] <<endl;
    return 0;
}


//normal matrix muplication
// for (i=0;i<m;i++)
//     for (j=0;j<n;j++)
//         for (k=0;k<m;k++)
//              C[i][j]=C[i][j]+A[i][k]*B[k][j];


// Stassen Matrix Multiplication
