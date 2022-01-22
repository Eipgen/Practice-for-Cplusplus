#include <iostream>
using namespace std;

int main()
{
    int day;
    
    cout <<"Please input a day:";
    cin >>day;

    switch (day)
    {
        case 0:
            cout << "Sun" << endl;
            break;
        case 1:
            cout << "Mon" << endl;
            break;
        case 2:
            cout << "Tue" << endl;
            break;
        case 3:
            cout << "Wed" << endl;
            break;
        case 4:
            cout << "Thu" << endl;
            break;
        case 5:
            cout << "Fri" << endl;
            break;
        case 6:
            cout << "Sat" << endl;
            break;
        default:
            cout << "out of range" << endl;
            break;
    }
    return 0;
}
