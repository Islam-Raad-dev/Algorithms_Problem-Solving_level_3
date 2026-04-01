/*

Count Letters

*/
#include <iostream>
#include <string>
using namespace std;

string ReadCharcter()
{

    string S1;

    cout << "Please Enter The String: ";
    getline(cin, S1);

    return S1;
}

short CountLetter(string S1, char C1)
{
    short Counter = 0;

    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            Counter++;
    }

    return Counter;
}

int main()
{
    string S1 = ReadCharcter();
    char C1;

    cout << "Please Enter A Charcter: ";
    cin >> C1;

    cout <<"Letter [" << C1 << "] Count = " << CountLetter(S1, C1) <<endl;

    return 0;
}