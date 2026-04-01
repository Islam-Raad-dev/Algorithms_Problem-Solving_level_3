/*

Reverse Word

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

vector<string> SplitString(string S1, string delim)
{
    vector<string> vString;

    short pos = 0;
    string sword;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sword = S1.substr(0, pos);

        if (sword != "")
        {
            vString.push_back(sword);
        }

        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

string ReverseWordInString(string S1)
{
    vector<string> vString;

    string S2 = "";

    vString = SplitString(S1, " ");

    vector<string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        --iter;

        S2 += *iter + " ";
    }

    S2 = S2.substr(0, S2.length() - 1);

    return S2;
}
int main()
{
    string S1 = ReadString();

    cout << "\nString After Reverse: \n";
    cout << ReverseWordInString(S1) << endl;

    return 0;
}