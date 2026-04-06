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

void ShowMainMenu();

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
    vector<string> vClientData = SplitString(Line, Seperator);

    if (vClientData.size() >= 5)
    {
        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.FullName = vClientData[2];
        Client.PhoneNumber = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);
    }
    return Client;
}

void PrintClientRecordLine(sClientInfo Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.FullName;
    cout << "| " << setw(12) << left << Client.PhoneNumber;
    cout << "| " << setw(12) << left << Client.AccountBalance;
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

bool ClientExistByAccountNumber(string AccountNumber, string FileName)
{
    vector<sClientInfo> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        sClientInfo Cleint;

        while (getline(MyFile, Line))
        {
            Cleint = ConvertLineDataToRecord(Line);
            if (Cleint.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
            vClients.push_back(Cleint);
        }
        MyFile.close();
    }
    return false;
}

sClientInfo ReadNewClient()
{
    sClientInfo Client;

    cout << "Enter Account Number: ";
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient With[" << Client.AccountNumber << "] Already Exists, Enter Andoter Account Number: ";
        getline(cin >> ws, Client.AccountNumber);
    }

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
void AddClientToFile(string FileName, string stDataLine)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }
}
void AddNewClients()
{

    sClientInfo Client;
    Client = ReadNewClient();
    AddClientToFile(ClientsFileName, ConvertRecordToLine(Client));
}
void AddNewClient()
{
    char AddMore = 'Y';

    do
    {
        cout << "Adding New Client:\n\n";

        AddNewClients();

        cout << "\nClirnt Added Successfuly, do you want To Add More Clients? (Y/N):";

        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

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
bool DeleteClintByAccountNumber(string AccountNumber, vector<sClientInfo> &vClients)
{
    sClientInfo Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\nAre you sure you want to delete this client? (Y/N): ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            MarkClintForDeleteByAccountNumber(AccountNumber, vClients);

            SaveClientDataToFile(ClientsFileName, vClients);

            vClients = LoadDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.\n";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number [" << AccountNumber << "] was NOT found.\n";
    }

    return false;
}
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

/*



 Statrt Of Main Fuction



*/
void ShowAllClientScreen()
{
    vector<sClientInfo> vClients = LoadDataFromFile(ClientsFileName);

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

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Client Available In The System!";

    else

        for (sClientInfo &Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    cout << "____________________________________________________________________________________________________\n"
         << endl;
}

void ShowAddNewClientScreen()
{
    cout << "\n-----------------------------------------------\n";
    cout << "\tAdd New Client Screen";
    cout << "\n-----------------------------------------------\n";

    AddNewClient();
}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------------------\n";

    vector<sClientInfo> vClients = LoadDataFromFile(ClientsFileName);

    string AccountNumber = ReadClientAccountNumber();

    DeleteClintByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------------------\n";
    cout << "\tUpdate Client Screen";
    cout << "\n-----------------------------------------------\n";

    vector<sClientInfo> vCleint = LoadDataFromFile(ClientsFileName);
    string AccountName = ReadClientAccountNumber();
    UpdateClintByAccountNumber(AccountName, vCleint);
}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------------------\n";

    vector<sClientInfo> vCleint = LoadDataFromFile(ClientsFileName);
    sClientInfo Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vCleint, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nCleint With Account Number[ " << AccountNumber << " ] is Not Found.\n";
    }
}

void ShowEndScreen()
{
    cout << "\n\nThank You For Using Our System.\n\n";
}

// End Of Main Menu Options Functions

void GoBackToMainMenu()
{
    cout << "\n\nPress Enter to return to Main Menu...";

    cin.ignore(100, '\n');
    cin.get();
}

short ReadMainMenuOption()
{
    short Choose;
    do
    {
        cout << "Enter Your Choose [1 - 6]: ";
        cin >> Choose;
    } while (Choose < 1 || Choose > 6);

    return Choose;
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOptions)
{

    switch (MainMenuOptions)
    {
    case enMainMenuOptions::eShow:
        system("clear");
        ShowAllClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eAdd:
        system("clear");
        ShowAddNewClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eDelete:
        system("clear");
        ShowDeleteClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eUpdate:
        system("clear");
        ShowUpdateClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eFind:
        system("clear");
        ShowFindClientScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eExit:
        system("clear");
        ShowEndScreen();
        exit(0);
        break;

    default:

        cout << "Invalid Choose, Try Again.";

        break;
    }
}

void ShowMainMenu()
{

    system("clear");
    cout << "=================================================================\n";
    cout << "\t\t\tMain Menue Screen";
    cout << "\n=================================================================\n";

    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Exit.";

    cout << "\n=================================================================\n";

    PerformMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}
int main()
{
    while (true)
    {
        ShowMainMenu();
    }
    return 0;
}