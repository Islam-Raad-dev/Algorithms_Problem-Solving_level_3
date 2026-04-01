/*

Split String

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

int main()
{

    vector<string> vString;

    vString = SplitString(ReadString(), " ");

    cout << "\nTokerns = " << vString.size() << endl;

    for (string &s : vString)
    {
        cout << s << endl;
    }

    return 0;
}