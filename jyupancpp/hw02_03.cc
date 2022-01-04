#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    long Second, Minute, Hour;
    Second = time(NULL);
    Minute = Second /60;
    Hour = Minute / 60;
    cout << "current time is:";
    cout << (Hour+8) % 24 << ":" << Minute % 60
    << ":" << Second % 60 << endl ;
    return 0;
}
