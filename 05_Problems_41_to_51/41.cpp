/*

Reverse Word

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

string ReverseWord(string S1)
{
    string Word;

    for(short i = 0; i < S1.length(); i++){
        
    }

    return Word;
}
int main()
{
    string S1 = ReadString();

    cout << "\nString After Reverse: \n";
    cout << ReverseWord(S1) << endl;

    return 0;
}