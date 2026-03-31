/*

Check Sparse Matrix

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

bool AreSparceMatrix(int Matrix1[3][3], short Rows, short Cols)
{

    int FirstDiagElement = Matrix1[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix1[i][j] != FirstDiagElement)
            {
                return false;
            }

            else if (i != j && Matrix1[i][j] != 0)
            {
                return true;
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3] = {{10, 0, 0}, {15, 20, 0}, {0, 0, 1}};

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