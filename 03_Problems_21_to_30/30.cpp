/*

Count Letters 

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

short CountSmallLetter(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            Counter++;
    }

    return Counter;
}

short CountCapitalLetter(string S1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadCharcter();

    cout << "\nString Length: " << S1.length();

    cout << "\nCapital Letters Count: " << CountCapitalLetter(S1);

    cout << "\nSmall Letters Count: " << CountSmallLetter(S1) << "\n";

    return 0;
}