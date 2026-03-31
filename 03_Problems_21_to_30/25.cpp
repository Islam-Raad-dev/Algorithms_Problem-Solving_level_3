/*

Lower Case First Letter Of Each Word

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
string UpperCaseLetterOfEachWord(string S1)
{

    bool isFirestLetter = true;

    for (short i = 0; i < S1.length(); i++)
    {

        if (S1[i] != ' ' && isFirestLetter)
        {
            S1[i] = tolower(S1[i]);
        }

        isFirestLetter = (S1[i] == ' ' ? true : false);
    }

    return S1;
}

int main()
{

    string S1 = ReadString();

    cout << "\nString After Upper Case: \n";

    S1 = UpperCaseLetterOfEachWord(S1);

    cout << "\n"<< S1 << endl;

    return 0;
}