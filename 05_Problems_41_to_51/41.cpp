/*

Join String (Overloading)

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector<string> vString, string delim)
{
    string S1;

    for (string &s : vString)
    {
        S1 = S1 + s + delim;
    }

    return S1.substr(0, S1.length() - delim.length());
}

string JoinString(string arrString, short Length, string delim)
{
    string S1 = " ";

    for (short i = 0; i < Length; i++)
    {
        S1 = S1 + arrString[i] + delim;
    }

    return S1.substr(0, S1.length() - delim.length());
}

int main()
{

    vector<string> vString = {"Mohammed", "Faid", "Ali", "Islam"};

    string arrString[] = {"Mohammed", "Faid", "Ali", "Islam"};

    cout << "\n Vector After Join :\n";
    cout << JoinString(vString, " ") << endl;

    cout << "\n Array After Join :\n";

    return 0;
}