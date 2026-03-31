/*

Fibonacci Series With Recursion

*/
#include <iostream>
using namespace std;

void PrintFibonacciUsingRecursion(short Number, int Prev2, int Prev1)
{

    int FebNumber = 0;

    if (Number > 0)
    {

        FebNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNumber;

        cout << FebNumber << "     ";

        PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);

        cout << endl;
    }
}

int main()
{

    short Number;

    cout << "Please Enter The Number: ";
    cin >> Number;
    cout << "\n";

    PrintFibonacciUsingRecursion(Number, 0, 1);

    return 0;
}