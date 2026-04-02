/*

Show All Clients

*/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<iomanip>

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

vector<string> LoadDataFromFile(string FileName){

}

void PrintClientRecord(sClientInfo Client){

}

void PrintAllClirntData(vector<string> vClient){

}

int main()
{
    vector<string> vClient;
    vClient = PrintClientRecord(Cl);

    PrintAllClirntData(vClient);

    return 0;
}