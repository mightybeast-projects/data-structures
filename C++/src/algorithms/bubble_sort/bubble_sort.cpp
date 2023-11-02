#include "bubble_sort.h"
#include <array>

void bubble_sort(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}