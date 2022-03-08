#include <iostream>
using namespace std;

int main()
{
    int x;
    int sign=0;
    
    cout <<"Please input a integer:";
    cin >>x;
    
    if (x<=0)
        if(x<0)
        {
            sign=-1;
        cout <<"sign is -"<<endl; 
        }
    else
        cout << "sign is +" <<endl;
    return 0;
}
