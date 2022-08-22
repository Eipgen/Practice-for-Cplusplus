#include <iostream>
using namespace std;

int main()
{
    enum weekday{sun=7, mon=1, tue, wed, thu, fri, sat};
    weekday today,dayafter;
    today = sun;
    cout << "today" << today << endl;
    dayafter = weekday(2);
    cout << "tomorrow" << dayafter << endl;
    return 0;
}