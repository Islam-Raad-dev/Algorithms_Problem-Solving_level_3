/*

Print Each Word in String

*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string ReadString()
{

    string S1;

    cout << "Please Enter The String: ";
    getline(cin, S1);

    return S1;
}

void PrintEachWord(string S1)
{

    string delim = " ";

    cout << "\nYour String Word Are: \n\n";

    short pos = 0;
    string sword;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sword = S1.substr(0, pos);

        if (sword != "")
        {
            cout << sword << endl;
        }

        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        cout << S1 << endl;
    }

}

int main()
{

    PrintEachWord(ReadString());

    return 0;
}