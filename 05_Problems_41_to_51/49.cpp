/*

Find Client By Account Number

*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClientInfo
{
    string AccountNumber;
    string PinCode;
    string FullName;
    string PhoneNumber;
    double AccountBalance;
};

string ReadCleintAccountNumber()
{
    string AccountNumber;

    cout << "Please Enter Account Number: ";
    cin >> AccountNumber;

    return AccountNumber;
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
            vString.push_back(sword);
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
    vector<string> vClientData = SplitString(Line, Seperator);

    if (vClientData.size() == 5)
    {
        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.FullName = vClientData[2];
        Client.PhoneNumber = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);
    }
    return Client;
}

vector<sClientInfo> LoadDataFromFile(string FileName)
{
    vector<sClientInfo> vClients;

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            if (Line != "")
            {
                sClientInfo Client = ConvertLineDataToRecord(Line);
                vClients.push_back(Client);
            }
        }
        MyFile.close();
    }

    return vClients;
}

void PrintClientCard(sClientInfo Client)
{

    cout << "\n\nThe Following is The Clint Recoed:\n";
    cout << "\nAccount Number   : " << Client.AccountNumber;
    cout << "\nPINCODE          : " << Client.PinCode;
    cout << "\nFull Name        : " << Client.FullName;
    cout << "\nPhone Number     : " << Client.PhoneNumber;
    cout << "\nAccount Blalance : " << Client.AccountBalance;
    cout << "\n";
}
bool FindClientByAccountNumber(string AccountNumber, sClientInfo &Client)
{

    vector<sClientInfo> vClients = LoadDataFromFile(ClientsFileName);

    for (sClientInfo &C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

int main()
{
    sClientInfo Client;

    string AccountNumber = ReadCleintAccountNumber();

    if (FindClientByAccountNumber(AccountNumber, Client))
    {

        PrintClientCard(Client);
    }

    else
    {
        cout << "\nClient With Account Number [" << AccountNumber << "] Is Not Fond.\n";
    }

    return 0;
}