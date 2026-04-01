/*

Reverse Word

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{

    string S1;

    cout << "Please Enter The String: ";
    getline(cin, S1);

    return S1;
}

string ReverseWord(){
    
}
int main()
{

    vector<string> vString = {"Mohammed", "Faid", "Ali", "Islam"};

    string arrString[] = {"Mohammed", "Faid", "Ali", "Islam"};

    cout << "\n Vector After Join :\n";
    cout << JoinString(vString, " ") << endl;

    cout << "\n Array After Join :\n";

    return 0;
}