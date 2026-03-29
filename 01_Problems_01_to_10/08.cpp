/*

Random 2 Matrix

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
            cout <<Matrix[i][j] << "    ";
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

void MultiplayMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResult[3][3], short Rows, short Cols){

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



    MultiplayMatrix(Matrix1, Matrix2, MatrixResult, 3, 3);

    cout << "\n\nResults: \n\n";

    PritnMatrix(MatrixResult, 3, 3);
    

    return 0;
}