/*

3 x 3 Oedered Matrix

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void FillMatrexWithOrderNumbers(int arr[3][3], short Rows, short Cols)
{

    short Counter = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Counter++;
            arr[i][j] = Counter;
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

    FillMatrexWithOrderNumbers(arr, 3, 3);

    cout << "\n\nThe Following is a 3 x 3 Ordered Matrix: \n\n";
    PritnMatrix(arr, 3, 3);

    cout << "\n\nThe Following is The Transposed Matrix: \n\n";
    PritnTransMatrix(arr, 3, 3);

    return 0;
}