#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

double mean(double x[],int n)
{
    int i;
    double sum=0.0;
    for (i=0;i<n;i++)
        sum+=x[i];
    return sum/n;
}

double deviation(double x[],int n)
{
    int i;
    double sum=0.0;
    double m=mean(x,n);
    for (i=0;i<n;i++)
        sum+=pow(x[i]-m,2);
    return sqrt(sum/n);
}


int main()
{
	int RandomNumber;
    int i;
    double x[100];
    for (i=0;i<100;i++)
    {
        RandomNumber=rand()%100;
        cout << RandomNumber << " ";
        x[i]=RandomNumber;
    }
    cout << "mean=" << mean(x,100) << endl;
    cout << "deviation=" << deviation(x,100) << endl;
    return 0;
}