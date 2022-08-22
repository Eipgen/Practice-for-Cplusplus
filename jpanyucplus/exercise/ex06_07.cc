#include <iostream>
#include <cmath>
using namespace std;

void findNprime(int *p, int N) // find N prime number
{
    int n = 2, k = 0, flag, i;
    while (k < N)
    {
        flag = 0;
        for(i=0;i<k && p[i]<=sqrt(n);i++)
            if (n%p[i]==0){flag = 1;break;}
        if (flag == 0){p[k]=n;k++;}
        n=n+1;
    }
}

int main()
{
    int N;
    cout << "Input N: ";
    cin >> N;

    int * pa = new int[N];

    findNprime(pa,N);
    cout << "min " << N << " of prime number is \n";
    for(int i=0; i<N; i++)
        cout << *(pa+i) << " ";
    cout << endl << endl;
    delete[] pa;
    return 0;
}