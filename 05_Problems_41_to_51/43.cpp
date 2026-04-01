/*

Replace Word(Custom)

*/
#include <iostream>
#include <string>

using namespace std;

string ReplaceWordInString(string S1, string ReplaceTo, string StringToReplace)
{
    short pos = S1.find(StringToReplace);

    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
        pos = S1.find(StringToReplace);
    }

    return S1;
}
int main()
{
    string S1 = "Welcome To Iraq, Iraq Is A Nice Place.";
    string StringToReplace = "Iraq";
    string ReplaceTo = "USA";

    cout << "\nString After Replace With Match Case: \n";
    cout << ReplaceWordInString(S1, StringToReplace, ReplaceTo) << endl;

    cout << "\nString After Replace: \n";
    cout << ReplaceWordInString(S1, StringToReplace, ReplaceTo) << endl;

    return 0;
}