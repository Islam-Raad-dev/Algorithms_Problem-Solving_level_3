/*

Intersected Numbber In Matrix

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
            cout << Matrix[i][j] << "    ";
        }

        cout << "\n";
    }
}

bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 0}};

    PritnMatrix(Matrix, 3, 3);

    int Number;
    cout << "\nEnter The Number To Count in Matrix: ";
    cin >> Number;

    if (IsNumberInMatrix(Matrix, Number, 3, 3))
    {
        cout << "\nYes, There Is.\n";
    }
    else
    {
        cout << "\nNo, There Is Not.\n";
    }
    return 0;
}