/*

Convert Record To Line

*/
#include <iostream>
#include <string>

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

int main()
{

    ClintInfo Info;

    cout << "\nClint Record For Saving is: \n";

    return 0;
}