#include <iostream>
#include "array-utils.h"

using namespace std;

namespace ArrayUtils
{
    void printArray(int *arr, int arrSize)
    {
        for (int i = 0; i < arrSize; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
}