#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char filename[FILENAME_MAX+ 1];
    cout << "filename enter: ";
    cin.getline(filename,FILENAME_MAX);
    ofstream file_out(filename);

    if (! file_out)
    {
        cout << filename << "can't open";
        cout << endl;
        return -1;
    }

    cout << filename << "Open" << endl;
    file_out << "I read it" << endl;
    file_out << "today news" << endl;
    file_out << "very happy" << endl;
    file_out.close();
    return 0;
}