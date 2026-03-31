/*

Fibonacci Series

*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void PritnMatrix(int Matrix[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << Matrix[i][j] << "    ";
        }

        cout << "\n";
    }
}

int IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] != Matrix1[j][Cols - 1 - j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 0}};

    cout << "\nMatrix :\n";
    PritnMatrix(Matrix1, 3, 3);

    if (IsPalindromeMatrix(Matrix1, 3, 3))
    {
        cout << "\nYes, The Matirx is not Palindrom. \n";
    }
    else
    {
        cout << "\nNo, The Matirx is Not Palindrom. \n";
    }


}