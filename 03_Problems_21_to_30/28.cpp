/*

Invert All Letter Case

*/
#include <iostream>
#include <string>
using namespace std;

string ReadCharcter()
{

    string S1;

    cout << "Please Enter The String: ";
    cin >> S1;

    return S1;
}

string InvertAllLetterCase(string S1)
{
    
}

int main()
{
    string S1 = ReadCharcter();

    cout << "\nChar After Inverting All Letter: \n";

    S1 = InvertAllLetterCase(S1);

    cout << S1 << endl;

    return 0;
}