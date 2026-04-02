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

ClintInfo ReadClintInfo()
{
    ClintInfo Info;

    cout << "Please Enter Clint Data:\n";
    cout << "\n-----------------------\n";

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

string ConvertRecordToLine(ClintInfo Clint, string delim)
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

    ClintInfo Clint;
    Clint = ReadClintInfo();

    cout << "\nClint Record For Saving is: \n";
    cout << ConvertRecordToLine(Clint, "#//") << endl;

    return 0;
}