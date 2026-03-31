/*

Numbber Exists In Matrix

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

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    short NumberCount = 0;

    for (short i = 0; i < Cols; i++)
    {
        for (short j = 0; j < Rows; j++)
        {
            if (Matrix1[i][j] == Number)
            {
                NumberCount++;
            }
        }
    }

    return NumberCount;
}

bool AreSparceMatrix(int Matrix1[3][3], short Rows, short Cols)
{

    short MatrixSize = Rows * Cols;

    return (CountNumberInMatrix(Matrix1, 0, 3, 3) >= (MatrixSize / 2));
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3] = {{12, 0, 0}, {0, 0, 1}, {0, 0, 9}};

    PritnMatrix(Matrix, 3, 3);

    if (AreSparceMatrix(Matrix, 3, 3))
    {
        cout << "\nYes, The Matrix is Sparce.\n " << endl;
    }
    else
    {
        cout << "\nNo, The Matrix is Not Sparce.\n " << endl;
    }
    return 0;
}