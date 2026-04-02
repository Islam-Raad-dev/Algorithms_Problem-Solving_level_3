/*

Show All Clients

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

void PrintClientRecordLine(sClientInfo Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.FullName;
    cout << "| " << setw(12) << left << Client.PhoneNumber;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintAllClientData(vector<sClientInfo> vClients)
{
    cout << "\n\t\t\t\tClient List [" << vClients.size() << "] Client(s).";
    cout << "\n____________________________________________________________________________________________________\n"
         << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n____________________________________________________________________________________________________\n"
         << endl;

    for (sClientInfo &Client : vClients)
    {
        PrintClientRecordLine(Client);
        cout << endl;
    }
    cout << "____________________________________________________________________________________________________\n"
         << endl;
}

int main()
{
    vector<sClientInfo> vClients = LoadDataFromFile(ClientsFileName);
    PrintAllClientData(vClients);
    return 0;
}