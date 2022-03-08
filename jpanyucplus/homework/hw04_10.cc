#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

bool isPrime(int x)
{
    if (x < 2)
        return false;
    for(int i=2;i<=sqrt(x);i++)
    {
        if((x%i)==0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "input number:";
    cin >> n;
    vector<int> prime;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(isPrime(i))
            prime.push_back(i);
    }
    
    for(int i=0;i<prime.size();i++)
    {
        if(n%prime[i]==0)
        {
            cout << prime[i] << " ";
            n=n/prime[i];
            i--;
        }
    }
    cout << endl;
    return 0;
}
