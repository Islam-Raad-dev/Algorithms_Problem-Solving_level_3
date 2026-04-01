/*

Count Vowel In String:

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

bool IsVowel(char C1)
{
    C1 = tolower(C1);

    return ((C1 == 'a') || (C1 == 'e') || (C1 == 'i') || (C1 == 'o') || (C1 == 'u'));
}

short CountVowel(string S1)
{

    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            Counter++;
    }

    return Counter++;
}

int main()
{
    string S1 = ReadString();

    cout << "\nNumber Of Vowel is: " << CountVowel(S1) << endl;

    return 0;
}