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

void PrintIntersectedNumbberInMatrix(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{

    short Number;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Number = Matrix1[i][j];

            if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
            {
                cout << setw(3) << Number << "     ";
            }
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 0}};
    int Matrix2[3][3] = {{5, 80, 90}, {22, 77, 1}, {10, 8, 33}};

    cout << "\nMatrix 1:\n";
    PritnMatrix(Matrix1, 3, 3);

    cout << "\nMatrix 2:\n";
    PritnMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Numbber Are: \n";
    PrintIntersectedNumbberInMatrix(Matrix1, Matrix2, 3, 3);

    return 0;
}