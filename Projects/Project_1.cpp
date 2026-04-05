/*


Bank 1:


*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const static string ClientsFileName = "Clients.txt";

enum enMainMenuOptions
{
    eShow = 1,
    eAdd = 2,
    eDelete = 3,
    eUpdate = 4,
    eFind = 5,
    eExit = 6
};

struct sClientInfo
{
    string AccountNumber;
    string PinCode;
    string FullName;
    string PhoneNumber;
    double AccountBalance;
    bool MarkForDelete = false;
};

//-------------------------------------
// Start of Show All Client List
//-------------------------------------

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

//-------------------------------------
// End of Show All Client List
//-------------------------------------

//-------------------------------------
// Start of Add New Client
//-------------------------------------

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

//-------------------------------------
// End of Add New Client
//-------------------------------------

//-------------------------------------
// Start of Delete Client
//-------------------------------------

string ReadClientAccountNumber()
{
    string AccountNumber;

    cout << "Please Enter Account Number: ";
    cin >> AccountNumber;

    return AccountNumber;
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
bool DeleteClintByAccountNumber(string AccountNumber, vector<sClientInfo> &vClient)
{

    sClientInfo Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClient, Client))
    {

        PrintClientCard(Client);

        cout << "\nAre You Sure That You Want To Delete This Client? (Y/N)";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClintForDeleteByAccountNumber(AccountNumber, vClient);

            SaveClientDataToFile(ClientsFileName, vClient);

            vClient = LoadDataFromFile(ClientsFileName);

            cout << "\n\nCleint Delete Succesfuly.\n";

            return true;
        }
    }
    else
    {
        cout << "\nCleint With Account Number[ " << AccountNumber << " ] is Not Found.\n";
    }

    return false;
}

//-------------------------------------
// End of Delete Client
//-------------------------------------

//-------------------------------------
// Start of Update Client
//-------------------------------------

sClientInfo ChanceClintRecord(string AccountNumber)
{

    sClientInfo Client;

    Client.AccountNumber = AccountNumber;

    cout << "\nEnter Your PINCODE: ";
    getline(cin >> ws, Client.PinCode);

    cout << "\nEnter Your Full Name: ";
    getline(cin, Client.FullName);

    cout << "\nEnter Your Phone Number: ";
    getline(cin, Client.PhoneNumber);

    cout << "\nEnter Your Account Balance: ";
    cin >> Client.AccountBalance;

    return Client;
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

            for (sClientInfo &C : vClient)
            {

                if (C.AccountNumber == AccountNumber)
                {
                    C = ChanceClintRecord(AccountNumber);
                    break;
                }
            }

            SaveClientDataToFile(ClientsFileName, vClient);

            vClient = LoadDataFromFile(ClientsFileName);

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

//-------------------------------------
// End of Update Client
//-------------------------------------

//-------------------------------------
// Start of Find Client
//-------------------------------------



void MainMenueScreen()
{

    system("clear");
    cout << "=================================================================\n";
    cout << "\t\t\tMain Menue Screen";
    cout << "\n=================================================================\n";

    cout << "[1] Show Client List.\n";
    cout << "[2] Add New Client.\n";
    cout << "[3] Delete Client.\n";
    cout << "[4] Update Client Info.\n";
    cout << "[5] Find Client.\n";
    cout << "[6] Exit.\n";
}
int main()
{
    MainMenueScreen();
    return 0;
}