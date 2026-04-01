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
string ReplaceWordInString(string S1)
{
}
int main()
{
    string S1 = ReadString();

    cout << "\nString After Replace: \n";
    cout << ReplaceWordInString(S1) << endl;

    return 0;
}