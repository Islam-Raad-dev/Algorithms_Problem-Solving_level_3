/*

Replace Word ( Custom )

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

string JoinString(vector<string> vString, string delim)
{
    string S1;

    for (string &s : vString)
    {
        S1 = S1 + s + delim;
    }

    return S1.substr(0, S1.length() - delim.length());
}

string LowerAllSplit(string S1)
{

    for (short i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }

    return S1;
}
string ReplaceWordUsingSplit(string S1, string ReplaceTo, string StringToReplace, bool Matchcase = true)
{
    vector<string> vString = SplitString(S1, " ");

    for (string &s : vString)
    {

        if (Matchcase)
        {
            if (s == StringToReplace)
            {
                s = ReplaceTo;
            }
        }

        else
        {
            if (LowerAllSplit(s) == LowerAllSplit(StringToReplace))
            {
                s = ReplaceTo;
            }
        }
    }

    return JoinString(vString, " ");
}
int main()
{
    string S1 = "Welcome To Iraq, Iraq Is A Nice Place.";
    string StringToReplace = "Iraq";
    string ReplaceTo = "USA";

    cout << "\nString After Replace With Match Case: \n";
    cout << ReplaceWordUsingSplit(S1, StringToReplace, ReplaceTo) << endl;

    cout << "\nString After Replace: \n";
    cout << ReplaceWordUsingSplit(S1, StringToReplace, ReplaceTo, false);

    return 0;
}