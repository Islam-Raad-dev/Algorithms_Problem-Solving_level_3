/*

Check Scalar Matrix

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

bool AreScalar(int Matrix1[3][3], short Rows, short Cols)
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

    int Matrix[3][3] = {{9, 0, 0}, {0, 9, 0}, {0, 0, 9}};

    PritnMatrix(Matrix, 3, 3);

    if (AreScalar(Matrix, 3, 3))
    {
        cout << "\nYes, The Matrix is Scalar.\n " << endl;
    }
    else
    {
        cout << "\nNo, The Matrix is Not Scalar.\n " << endl;
    }
    return 0;
}