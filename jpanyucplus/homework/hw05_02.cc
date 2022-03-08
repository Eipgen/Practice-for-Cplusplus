#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int count(int x[],int n,int k)
{
    int i;
    int count=0;
    for (i=0;i<n;i++)
        if (x[i]==k)
            count++;
    return count;
}

int removeDepulicate(int x[],int n)
{
    int i,j;
    for (i=0;i<n;i++)
        for (j=i+1;j<n;j++)
            if (x[i]==x[j])
            {
                x[j]=x[n-1];
                n--;
                j--;
            }
    return n;    
}



int main()
{
	int RandomNumber;
    int i;
    int x[100];
    int m;
    for (i=0;i<100;i++)
    {
        RandomNumber=rand()%9+1;
        // cout << RandomNumber << " ";
        x[i]=RandomNumber;
    }
    m=removeDepulicate(x,100);
       
    int j;
    for (j=1;j<m;j++)
        cout << "num is count(" << x[j] << ")=" << count(x,100,x[j]) << endl;
    return 0;

}