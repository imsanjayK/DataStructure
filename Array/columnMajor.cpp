//#include <stdio.h>
#include <iostream>
using namespace std;
#define size 10
int main()
{
    int row = 3, col = 3;
    int array[size][size];

    for (int indexJ = 0; indexJ < col; ++indexJ) //column major
    {
        for (int indexI = 0; indexI < row; ++indexI)
        {
            //scanf("%d", &(array[indexI][indexJ]));
            cin >> array[indexI][indexJ];
        }
    }
    for (int indexI = 0; indexI < row; ++indexI)
    {
        for (int indexJ = 0; indexJ < col; ++indexJ)
        {
            // printf("%d", array[indexI][indexJ]);
            cout << array[indexI][indexJ] << " ";
        }
        cout << endl;
    }
    return 0;
}