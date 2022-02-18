#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

void reverse(int x[],int n)
{
    int i;
    int j;
    int temp;
    for (i=0,j=n-1;i<j;i++,j--)
    {
        temp=x[i];
        x[i]=x[j];
        x[j]=temp;
    }
}

int main()
{
	int RandomNumber;
    int i;
    int x[10];
    int m;
    for (i=0;i<10;i++)
    {
        RandomNumber=rand()%9+1;
        cout << RandomNumber << " ";
        x[i]=RandomNumber;
    }
    cout << "F"<<endl;
    //int y[10];
    reverse(x,10);
    for (int j=0;j<10;j++)
        cout << x[j] << " ";
    cout << "R" <<endl;
    return 0;
}