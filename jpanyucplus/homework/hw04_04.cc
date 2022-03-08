#include <iostream>
#include <cstdio>
#include <ctime>


using namespace std;

int main()
{
    srand ( time(NULL) );
    int userlevel;
    int userinput;
    int randomNumber;
    
    int No_of_G= (rand()%10+1);
    int Nchance = 10;

    cout << "You have "  << Nchance << " chances to guess right" << endl;
    while(Nchance !=0)
    {
        cout  << "Guess:";
        cin >> userinput;
        if(userinput == No_of_G)
        {
            cout << "You win"<<endl;
            break;
        }
        Nchance--;
    }
    if (Nchance == 0){
        cout << "you fail" << endl;
    }
    return 0;
}
