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

vector<string> LoadDataFromFile(string FileName)
{
    vector<string> vClients;

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {

        string Line;
        sClientInfo Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineDataToRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }
}

void PrintClientRecord(sClientInfo Client)
{
}

void PrintAllClirntData(vector<string> vClient)
{
}

int main()
{
    vector<string> vClient = LoadDataFromFile(ClientsFileName);

    PrintAllClirntData(vClient);

    return 0;
}