/*

Is Vowel:

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

char ReadChar()
{

    char C1;

    cout << "Please Enter A Charcter: ";
    cin >> C1;

    return C1;
}

short CountLetter(string S1, char C1, bool Matchcase = true)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (Matchcase)
        {
            if (S1[i] == C1)
                Counter++;
        }

        else
        {
            if (tolower(S1[i]) == tolower(C1))
                Counter++;
        }
    }

    return Counter;
}

char InvertCharcterCase(char C1)
{
    return isupper(C1) ? tolower(C1) : toupper(C1);
}

int main()
{
    string S1 = ReadCharcter();
    char C1 = ReadChar();

    cout << "Letter [ " << C1 << " ] " << "Or [ " << InvertCharcterCase(C1) << " ]Count = " << CountLetter(S1, C1, false) << endl;

    return 0;
}