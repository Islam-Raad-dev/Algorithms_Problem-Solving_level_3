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

struct sClientInfo
{
    string AccountNumber;
    string PinCode;
    string FullName;
    string PhoneNumber;
    double AccountBalance;
    bool MarkForDelete = false;
};

void MainMenueScreen(){
    cout<<"=================================================================\n";
    cout<<"\t\t\tMain Menue Screen";
    cout<<"\n=================================================================\n";
}

void 
int main()
{
    MainMenueScreen();
    return 0;
}