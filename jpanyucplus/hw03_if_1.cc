#include <iostream>
using namespace std;

int main()
{
    int x;
    int sign=0;
    
    cout <<"Please input a integer:";
    cin >>x;
    
    if ((90<x)&&(x<100))
        cout <<"A"<<endl; 
    else if ((80<x) && (x<89)) 
        cout << "B" <<endl;
    else if ((70<x)&&(x<79))
        cout << "C" <<endl;
    else if ((60<x)&&(x<69))
        cout << "D" <<endl;
    else
        cout << "E" <<endl;
    return 0;
}
