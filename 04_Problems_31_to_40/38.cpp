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
}

string TrimRight(string S1)
{
}

string Trim(string S1)
{
}

int main()
{

    string S1 = ReadString();

    cout << "\nString = " << S1 << endl;
    cout << "\nTrim Left = " << TrimLeft(S1) << endl;
    cout << "\nTrim Right = " << TrimRight(S1) << endl;
    cout << "\nTrim  = " << Trim(S1) << endl;

    return 0;
}