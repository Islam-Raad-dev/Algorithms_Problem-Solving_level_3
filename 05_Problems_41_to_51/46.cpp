/*

Convert Line Data To Record

*/
#include <iostream>
#include <string>
#include <vector>

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

string ConvertLineDataToRecord(sClientInfo Clint, string Sepreator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Clint.AccountNumber + Sepreator;
    stClientRecord += Clint.PinCode + Sepreator;
    stClientRecord += Clint.FullName + Sepreator;
    stClientRecord += Clint.PhoneNumber + Sepreator;
    stClientRecord += to_string(Clint.AccountBalance);

    return stClientRecord;
}

int main()
{

    const string LineRecord = "A150#//#1234#//#Islam Raad#//#07783234#//#5270.000000";

    sClientInfo Client;
    Client = ReadNewClient();

    cout << "\nThe Following is The Extracted Clint Record: \n\n";

    cout << ConvertLineDataToRecord(Client) << "\n"
         << endl;

    return 0;
}