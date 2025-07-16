#include "limits.h"
#include "stdio.h"

void numberLimits()
{
    printf("Integer (signed):\n");
    printf("Limits of an integer: [%d --> %d]\n", INT_MIN, INT_MAX);
    printf("Limits of a short integer: [%d --> %d]\n", SHRT_MIN, SHRT_MAX);
    printf("Limits of a long integer: [%ld --> %ld]\n", LONG_MIN, LONG_MAX);

    printf("Integer (unsigned):\n");
    printf("Limits of an integer: [0 --> %u]\n", UINT_MAX);
    printf("Limits of a short integer: [0 --> %u]\n", USHRT_MAX);
    printf("Limits of a long integer: [0 --> %lu]\n", ULONG_MAX);
}