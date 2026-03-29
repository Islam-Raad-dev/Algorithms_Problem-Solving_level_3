/*

3 x 3 Oedered Matrix

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{

    int randNumb = rand() % (To - From + 1) + From;

    return randNumb;
}

void FillMatrexWithOrderNumbers(int arr[3][3], short Rows, short Cols)
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
            cout << setw(3) << arr[i][j] << "    ";
        }

        cout << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];

    FillMatrexWithOrderNumbers(arr, 3, 3);

    cout << "\n\nThe Following is a 3 x 3 Random Matrix: \n\n";

    PritnMatrix(arr, 3, 3);

    cout << "\n\n";

    return 0;
}
