/*

3 x 3 Random Matrix

*/
#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

int RandomNumber(int From, int To)
{

    int randNumb = rand() % (To - From + 1) + From;

    return randNumb;
}

void FillMatrexWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{



}

void PritnMatrix(int arr[3][3], short Rows, short Cols){

}
int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrexWithRandomNumbers(arr, 3, 3);
    
    cout<<"\nThe Following is a 3x3 Random Matrix: \n";

    PritnMatrix(arr, 3, 3);

    system("pause>0");

    return 0;
}
