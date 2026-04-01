/*

Count Each Word in String

*/
#include <iostream>
#include <string>
using namespace std;

string ReadString()
{

    string S1;

    cout << "Please Enter The String: ";
    getline(cin, S1);

    return S1;
}

short CountEachWordinString(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        S1[i];
        Counter++;
    }

    return Counter;
}

int main()
{

    string S1 = ReadString();

    cout << "\nThe Number Of Each Word in Your String Is: ";
    cout << CountEachWordinString(S1) << endl;

    return 0;
}