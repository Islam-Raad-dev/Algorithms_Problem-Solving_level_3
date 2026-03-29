/*

Print Sum Of Random Matrix

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

void SumOfMatrix(int Matrix1[3][3], short Rows, short Cols){

}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3];

    FillMatrexWithRandomNumbers(Matrix1, 3, 3);

    cout << "Matrix 1: \n\n";
    PritnMatrix(Matrix1, 3, 3);

    cout << "\nSum OF The Matrixs is: \n\n";
    SumOfMatrix(Matrix1, 3, 3);

    return 0;
}
