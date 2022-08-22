/*
#include <stdio.h>
#define NDOORS 100

int main() 
{
    int doors[NDOORS] ={0};
    for (int j=1;j<=NDOORS;j++)
    {
        for (int i=j-1;i<NDOORS;i++)
        {
            doors[i]=1-doors[i];
        }
    }
    for (int c=0;c<NDOORS;c++)
    {
            if (doors[c]==1)
        {
        printf("%d ",c+1); 
        }
    }
    return 0;
}
*/
// locker student problem

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
    int Tstudent,Tlocker,visit,Topen=0,Tclose=0;

    cout << "Enter the number of Tstudents: " << endl;
    cin >> Tstudent;
    Tlocker = Tstudent;

    for (int locker=1; locker < Tlocker; locker++)
    {
        cout << " Locker no " << locker << endl;
        cout << "is visited by students ";
        visit = 0;
        for (int student=1;student <Tstudent;student++)
        {
            if (locker % student == 0) 
            {
                cout << student << ",";
                visit++;
            } 
        }

        cout <<"\n Total number of visits: " << visit;
        if (visit %2 ==0)
        {
            cout << " the locker will stay closed.";
            Tclose++;
        }
        else
        {
            cout << " the locker will be opened.";
            Topen++;
        }

    } //end of student loop

    if (Tlocker == Topen + Tclose) 
    {
        cout << "\n\n\nOf total lockers (" << Tlocker << "), " << Topen << " will be left open." << "(" << Tclose << ") " << "will be closed." << endl;
    }
    else cout << "Error!!";
    return 0;
}