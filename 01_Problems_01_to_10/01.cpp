/*

3 x 3 Random Matrix

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
            cout << setw(3) << arr[i][j] << "    ";
        }

        cout << "\n";
    }
}
int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrexWithRandomNumbers(arr, 3, 3);

    cout << "\nThe Following is a 3x3 Random Matrix: \n";

    PritnMatrix(arr, 3, 3);

    return 0;
}
