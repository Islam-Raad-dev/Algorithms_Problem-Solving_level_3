/*

Add Clients To File

*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct sClientInfo
{

    string AccountNumber;
    string PinCode;
    string FullName;
    string PhoneNumber;
    double AccountBalance;
};

sClientInfo ReadNewClient()
{
    sClientInfo Client;

    cout << "Please Enter Client Data:\n";
    cout << "-----------------------\n";

    cout << "Enter Account Number: ";
    getline(cin, Client.AccountNumber);

    cout << "\nEnter Your PINCODE: ";
    getline(cin, Client.PinCode);

    cout << "\nEnter Your Full Name: ";
    getline(cin, Client.FullName);

    cout << "\nEnter Your Phone Number: ";
    getline(cin, Client.PhoneNumber);

    cout << "\nEnter Your Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(sClientInfo Clint, string Sepreator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Clint.AccountNumber + Sepreator;
    stClientRecord += Clint.PinCode + Sepreator;
    stClientRecord += Clint.FullName + Sepreator;
    stClientRecord += Clint.PhoneNumber + Sepreator;
    stClientRecord += to_string(Clint.AccountBalance);

    return stClientRecord;
}

void StratAdd()
{

    sClientInfo Client;
    Client = ReadNewClient();
    char AddMore = 'Y';

    do
    {

        cout << "\nClint Added Seccessfully, \nDo You Want To Add More Client ? (Y/N): ";
        cin >> AddMore;
    } while (AddMore == 'Y' || AddMore == 'y');
}

int main()
{
    StratAdd();

    return 0;
}