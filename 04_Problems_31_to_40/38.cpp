/*

TrimLeft / TrimRight / Trim

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
string TrimLeft(string S1)
{

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - i);
        }
    }
}

string TrimRight(string S1)
{

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - i);
        }
    }
}

string Trim(string S1)
{

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - i);
        }
    }
}

int main()
{

    string S1 = ReadString();

    cout << "\nString     = " << S1 << endl;
    cout << "\n\nTrim Left  = " << TrimLeft(S1) << endl;
    cout << "\nTrim Right = " << TrimRight(S1) << endl;
    cout << "\nTrim       = " << Trim(S1) << endl;

    return 0;
}