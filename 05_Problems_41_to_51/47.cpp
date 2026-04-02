/*

Add Clients To File

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

sClientInfo ConvertLineDataToRecord(string Line, string Seperator = "#//#")
{
    sClientInfo Client;

    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.FullName = vClientData[2];
    Client.PhoneNumber = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

void PrintClientRecord(sClientInfo Client)
{

    cout << "\n\nThe Following is The Clint Recoed:\n";
    cout << "\nAccount Number   : " << Client.AccountNumber;
    cout << "\nPINCODE          : " << Client.PinCode;
    cout << "\nFull Name        : " << Client.FullName;
    cout << "\nPhone Number     : " << Client.PhoneNumber;
    cout << "\nAccount Blalance : " << Client.AccountBalance;
    cout << "\n";
}

int main()
{

    string sLine = "A150#//#1234#//#Islam Raad#//#07783234#//#5270.000000";

    cout << "\nLine Record is: \n\n";
    cout << sLine;

    sClientInfo Client = ConvertLineDataToRecord(sLine);

    PrintClientRecord(Client);

    return 0;
}