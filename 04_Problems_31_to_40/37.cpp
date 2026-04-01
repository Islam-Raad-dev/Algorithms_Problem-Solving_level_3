/*

Split String

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

short CountEachWordinString(string S1)
{

    string delim = " ";
    short Counter = 0;
    short pos = 0;
    string sword;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sword = S1.substr(0, pos);

        if (sword != "")
        {
            Counter++;
        }

        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        Counter++;
    }

    return Counter;
}

int main()
{

    string S1 = ReadString();

    cout << "\nThe Number Of Each Word in Your String Is: ";
    cout << CountEachWordinString(S1) << endl;

    return 0;
}