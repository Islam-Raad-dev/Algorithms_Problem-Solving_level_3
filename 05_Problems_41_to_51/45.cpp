/*

Convert Record To Line

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ClintInfo
{

    int AccountNumber;
    short PinCode;
    string FullName;
    int PhoneNumber;
    int AccountBalance;
};

int ReadClintInfo(ClintInfo Info)
{

    cout << "Enter Your Number: ";
    cin >> Info.AccountNumber;

    cout << "Enter Your PINCODE: ";
    cin >> Info.PinCode;

    cout << "Enter Your Full Name: ";
    getline(cin, Info.FullName);

    cout << "Enter Your Phone Number: ";
    cin >> Info.PhoneNumber;

    cout << "Enter Your Account Balance: ";
    cin >> Info.AccountBalance;

    return Info;
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

int main()
{

    ClintInfo Info;
    vector<string> vString;

    cout << "\nClint Record For Saving is: \n";
    cout << JoinString(vString, "#//") << endl;

    return 0;
}