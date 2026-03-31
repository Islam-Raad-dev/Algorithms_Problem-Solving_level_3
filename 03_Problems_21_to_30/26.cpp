/*

Upper / Lower All Letter Of String

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
string UpperCaseAllLetter(string S1)
{

    for (short i = 0; i < S1.length(); i++)
    {

        S1[i] = toupper(S1[i]);
    }

    return S1;
}

string LowerCaseAllLetter(string S1)
{

    for (short i = 0; i < S1.length(); i++)
    {

        S1[i] = tolower(S1[i]);
    }

    return S1;

}
int main()
{

    string S1 = ReadString();

    cout << "\nString After Upper Case: \n";

    S1 = UpperCaseAllLetter(S1);

    cout << S1 << endl;

    cout << "\nString After Lower Case: \n";

    S1 = LowerCaseAllLetter(S1);

    cout << S1 << endl;

    return 0;
}