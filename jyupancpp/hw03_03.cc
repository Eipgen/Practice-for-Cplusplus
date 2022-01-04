#include <iostream>
#include <cmath>
using namespace std;

int prime(int x){
    int k,m;

    //cout <<"Please input a integer:";
    //cin >>x;

    if (x &1)
        x -=2;
    else
        x--;
    if (x==1)
        cout << "eorr " <<endl;
    else
        for (k=x;k>=2;k-=2){
            if (k %2==0)
                continue;
            for(m=3;m<=sqrt(k);m+=2){ 
                if (k%m == 0)
                    break;
            }
        
            if (m >sqrt(k))
                return k;
        }
    return 2;
}
int main()
{
    //int x=17;
    int x;
    cout <<"Please input a integer:";
    cin >>x;
    cout << prime(x) << " is a prime" << endl;
    return 0;
}
