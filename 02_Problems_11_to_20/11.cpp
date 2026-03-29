/*

Check Matrix Eguality

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{

    int randNumb = rand() % (To - From + 1) + From;

    return randNumb;
}

void FillMatrexWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            arr[i][j] = RandomNumber(1, 100);
        }
    }
}

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

void PritnTransMatrix(int Matrix[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << Matrix[j][i] << "    ";
        }

        cout << "\n";
    }

    cout << "\n";
}

int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
{

    int Sum = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Sum += Matrix1[i][j];
        }
    }

    cout << "\n";

    return Sum;
}
bool AreEqualMatrix(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3], MatrixResult[3][3];

    FillMatrexWithRandomNumbers(Matrix1, 3, 3);
    cout << "\n\nMatrix 1: \n\n";
    PritnMatrix(Matrix1, 3, 3);

    FillMatrexWithRandomNumbers(Matrix2, 3, 3);
    cout << "\n\nMatrix 2: \n\n";
    PritnMatrix(Matrix2, 3, 3);

    if (AreEqualMatrix(Matrix1, Matrix2, 3, 3))
    {
        cout << "\nYes, Both Are Equal. ";
    }
    else
    {
        cout << "\nNo, Matrix Are Not Equal. ";
    }
    return 0;
}