/*

Print First Letter Of Each Word

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
void PrintFirstLetter(string S1)
{

    bool isFirestLetter = true;

    cout << "\nFirst Letter Of This String \n";

    for (short i = 0; i < S1.length(); i++)
    {

        if (S1[i] != ' ' && isFirestLetter)
        {
            cout << S1[i] << endl;
        }

        isFirestLetter = (S1[i] == ' ' ? true : false);
    }
}
int main()
{

    PrintFirstLetter(ReadString());

    return 0;
}