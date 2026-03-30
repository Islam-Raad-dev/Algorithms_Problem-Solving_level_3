/*

Count Number In Matrix

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
int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3] = {{9, 1, 12}, {0, 9, 1}, {0, 9, 9}};

    cout << "Matrix : \n";
    PritnMatrix(Matrix, 3, 3);

    int Number;
    cout << "\nEnter The Number To Count in Matrix: ";
    cin >> Number;

    cout << "\nNumber [" << Number << "] Count In Matrix is [" << CountNumberInMatrix(Matrix, Number, 3, 3) << "]." << endl;

    return 0;
}