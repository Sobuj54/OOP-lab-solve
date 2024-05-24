/*
4. append file
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string c;
    fstream fI, fO;
    fI.open("read.txt", ios::in);
    fO.open("write.txt", ios::out | ios::app);
    if (!fO)
    {
        cout << "error" << endl;
    }
    else
    {
        while (getline(fI, c))
        {
            fO << c;
            fO << " ";
        }
    }
    fI.close();
    fO.close();
    return 0;
}