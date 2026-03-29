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

void PritnMatrix(int arr[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << arr[i][j] << "    ";
        }

        cout << "\n";
    }
}

void PritnTransMatrix(int arr[3][3], short Rows, short Cols)
{

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << arr[j][i] << "    ";
        }

        cout << "\n";
    }

    cout << "\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];

    FillMatrexWithRandomNumbers(arr, 3, 3);

    cout << "\n\nMatrix 1: \n\n";
    PritnMatrix(arr, 3, 3);

    cout << "\n\nMatrix 2: \n\n";
    PritnMatrix(arr, 3, 3);

    cout << "\n\nResults: \n\n";
    PritnMatrix(arr, 3, 3);

    return 0;
}