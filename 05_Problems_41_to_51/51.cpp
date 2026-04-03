/*

Update Client By Account Number

*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const static string ClientsFileName = "Clients.txt";

struct sClientInfo
{
    string AccountNumber;
    string PinCode;
    string FullName;
    string PhoneNumber;
    double AccountBalance;
    bool MarkForDelete = false;
};

string ReadClientAccountNumber()
{
    string AccountNumber;

    cout << "Please Enter Account Number: ";
    cin >> AccountNumber;

    return AccountNumber;
}

vector<string> SplitString(string S1, string delim)
{
    vector<string> vString;
    size_t pos = 0;
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

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.FullName = vClientData[2];
    Client.PhoneNumber = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

vector<sClientInfo> LoadDataFromFile(string FileName)
{
    vector<sClientInfo> vClients;

    fstream MyFile;

    MyFile.open(FileName, ios::in); // Read Mode

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
bool FindClientByAccountNumber(string AccountNumber, vector<sClientInfo> &vClients, sClientInfo &Client)
{

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
bool MarkClintForDeleteByAccountNumber(string AccountNumber, vector<sClientInfo> &vClient)
{

    for (sClientInfo &C : vClient)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;

            return true;
        }
    }

    return false;
}
vector<sClientInfo> SaveClientDataToFile(string FileName, vector<sClientInfo> &vClient)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out);

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClientInfo &C : vClient)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClient;
}
vector<sClientInfo> UpdateClintInfo(string AccountNumber, vector<sClientInfo> &vClient)
{
}
bool UpdateClintByAccountNumber(string AccountNumber, vector<sClientInfo> &vClient)
{

    sClientInfo Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClient, Client))
    {

        PrintClientCard(Client);

        cout << "\nAre You Sure That You Want To Update This Client? (Y/N)";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            for (sClientInfo C : vClient)
            {

                if (C.AccountNumber == AccountNumber)
                {
                }
            }

            cout << "\n\nCleint Updated Succesfuly.\n";

            return true;
        }
    }
    else
    {
        cout << "\nCleint With Account Number[ " << AccountNumber << " ] is Not Found.\n";
    }

    return false;
}

int main()
{

    vector<sClientInfo> vClient = LoadDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    UpdateClintByAccountNumber(AccountNumber, vClient);

    return 0;
}