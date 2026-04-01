/*

Is Vowel:

*/
#include <iostream>
#include <string>
using namespace std;

char ReadChar()
{

    char C1;

    cout << "Please Enter A Charcter: ";
    cin >> C1;

    return C1;
}

bool IsVowel(char C1)
{
    return ((C1 == 'a') || (C1 == 'e') || (C1 == 'i') || (C1 == 'o') || (C1 == 'u'));
}
int main()
{
    char C1 = ReadChar();

    if (IsVowel(C1))
    {
        cout << "Yes, The Letter [" << C1 << "] Is Vowel." << endl;
    }
    else
    {
        cout << "No, The Letter [" << C1 << "] Is Not Vowel." << endl;
    }

    return 0;
}