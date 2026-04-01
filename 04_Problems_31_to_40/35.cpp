/*

Print Each Word in String

*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string ReadString()
{

    string S1;

    cout << "Please Enter The String: ";
    getline(cin, S1);

    return S1;
}

bool IsVowel(char C1)
{
    C1 = tolower(C1);

    return ((C1 == 'a') || (C1 == 'e') || (C1 == 'i') || (C1 == 'o') || (C1 == 'u'));
}

void PrintEachWord(string S1)
{

    cout << "\nYour String Word Are: ";
    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
        {
            cout << S1[i] << "    ";
        }
    }
    cout << "\n";
}

int main()
{
    
    PrintEachWord(ReadString());

    return 0;
}