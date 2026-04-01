/*

Count Small / Capital Letters

*/
#include <iostream>
#include <string>
using namespace std;

string ReadCharcter()
{

    string S1;

    cout << "Please Enter The String: ";
    getline(cin, S1);

    return S1;
}

char InvertCharcterCase(char C1)
{
    return isupper(C1) ? tolower(C1) : toupper(C1);
}

string InvertAllLetterCase(string S1)
{

    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertCharcterCase(S1[i]);
    }

    return S1;
}

int main()
{
    string S1 = ReadCharcter();

    cout << "\nString Length: " << S1.length() << endl;

    cout<<"Capital Letters: "<<<<endl;
    return 0;
}