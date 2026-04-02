/*

Convert Record Ta Line

*/
#include <iostream>
#include <string>

using namespace std;

string RemovePunctuation(string S1)
{
    string S2 = " ";

    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }

    return S2;
}
int main()
{
    string S1 = "Welcome To Iraq, Iraq Is A Nice Place.";

    cout << "\nOriginal String: \n\n"
         << S1;

    cout << "\n\nPunctuation Remove: \n\n";
    cout << RemovePunctuation(S1) << "\n" << endl;

    return 0;
}