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
    float AccountBalance;
};

int ReadClintInfo(ClintInfo Info)
{

    cout<<"Please Enter Clint Data:\n";
    cout<<"\n-----------------------\n";

    cout << "Enter Account Number: ";
    cin >> Info.AccountNumber;

    cout << "\nEnter Your PINCODE: ";
    cin >> Info.PinCode;

    cout << "\nEnter Your Full Name: ";
    getline(cin, Info.FullName);

    cout << "\nEnter Your Phone Number: ";
    cin >> Info.PhoneNumber;

    cout << "\nEnter Your Account Balance: ";
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