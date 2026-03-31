/*

Min / Max Numbber In Matrix

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

int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{

    short Min = Matrix1[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {

            if (Matrix1[i][j] < Min)
            {
                Min = Matrix1[i][j];
            }
        }
    }

    return Min;
}

int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{

    short Max = Matrix1[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {

            if (Matrix1[i][j] > Max)
            {
                Max = Matrix1[i][j];
            }
        }
    }

    return Max;
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 0}};

    cout << "\nMatrix 1:\n";
    PritnMatrix(Matrix1, 3, 3);

    cout << "\nMin Numbber Are: "
         << MinNumberInMatrix(Matrix1, 3, 3) << endl;

    cout << "\nMax Numbber Are: "
         << MaxNumberInMatrix(Matrix1, 3, 3) << endl;

    return 0;
}