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

void MainMenueScreen()
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
    cout << "\t[6] Exit.\n";
}
int main()
{
    MainMenueScreen();
    return 0;
}