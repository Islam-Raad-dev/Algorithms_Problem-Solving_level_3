/*

Invert Charcter Case

*/
#include <iostream>
#include <string>
using namespace std;

char ReadCharcter()
{

    char C1;

    cout << "Please Enter The Charcter: ";
    cin >> C1;

    return C1;
}

char InvertCharcterCase(char C1)
{
    return isupper(C1) ? tolower(C1) : toupper(C1);
}

int main()
{
    char Ch1 = ReadCharcter();

    cout << "\nChar After Inverting Case: \n";

    Ch1 = InvertCharcterCase(Ch1);

    cout << Ch1 << endl;

    return 0;
}