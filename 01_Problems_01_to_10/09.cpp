/*

Print Middle Row And Cols Of Matrix

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

void FillMatrexWithRandomNumbers(int Matrix1[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix1[i][j] = RandomNumber(1, 100);
        }
    }
}

void PritnMatrix(int Matrix1[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            printf("%0*d     ", 2, Matrix1[i][j]);
        }

        cout << "\n";
    }
}

void PritnMiddleRow(int Matrix1[3][3], short Rows, short Cols)
{

    short MiddleRow = Rows / 2;

    for (short i = 0; i < Cols; i++)
    {

        printf("%0*d     ", 2, Matrix1[MiddleRow][i]);
    }

    cout << "\n";
}

void PrintMiddleCols(int Matrix1[3][3], short Rows, short Cols)
{

    short MiddleCol = Cols / 2;

    for (short i = 0; i < Rows; i++)
    {

        printf("%0*d     ", 2, Matrix1[i][MiddleCol]);
    }

    cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];

    FillMatrexWithRandomNumbers(Matrix1, 3, 3);

    cout << "Matrix 1: \n\n";
    PritnMatrix(Matrix1, 3, 3);

    cout << "\n\nMiddle Row Of The Matrixs: \n\n";
    PritnMiddleRow(Matrix1, 3, 3);

    cout << "\n\nMiddle Cols Of The Matrixs: \n\n";
    PrintMiddleCols(Matrix1, 3, 3);

    return 0;
}
