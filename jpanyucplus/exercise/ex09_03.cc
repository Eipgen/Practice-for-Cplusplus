#include <iostream>
#include <cstdlib>
using namespace std;

class Clock
{
    public:
        Clock();
        Clock(int h, int m, int s);
        void Showtime();
    private:
        int hour,minute,second;
};

Clock::Clock()
{
    hour = 0;
    minute = 0;
    second = 0;
}

Clock::Clock(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

inline void Clock::Showtime()
{
    cout << hour << ":" << minute << ":" << second << endl;
}

int main()
{
    Clock c1;
    Clock c2(8,30,30);
    cout << "c1: "; c1.Showtime();
    cout << "c2: "; c2.Showtime();
    cout << endl;
    return 0;
}