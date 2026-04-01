/*

Replace Word

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{

    string S1;

    cout << "Please Enter The String: ";
    getline(cin, S1);

    return S1;
}
string ReplaceWordInString(string S1, string ReplaceTo, string StringToReplace)
{
    
}
int main()
{
    string S1 = ReadString();
    string StringToReplace = "IRAQ";
    string ReplaceTo = "USA";

    cout << "\nString After Replace: \n";
    cout << ReplaceWordInString(S1, StringToReplace, ReplaceTo) << endl;

    return 0;
}