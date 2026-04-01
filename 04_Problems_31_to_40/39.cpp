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

    return "";
}

string TrimRight(string S1)
{

    for (short i = S1.length(); i >= 0; i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(0, i + 1);
        }
    }

    return "";
}

string Trim(string S1)
{
    return (TrimLeft(TrimRight(S1)));
}

int main()
{

    string S1 = ReadString();

    cout << "\nTrim Left  = " << TrimLeft(S1) << endl;
    cout << "\nTrim Right = " << TrimRight(S1) << endl;
    cout << "\n   Trim    = " << Trim(S1) << endl;

    return 0;
}