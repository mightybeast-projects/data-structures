#include "float.h"
#include "limits.h"
#include "stdio.h"

void typesLimits()
{
    printf("Integer (signed | default):\n");
    printf("Limits of an integer: [%d --> %d]\n", INT_MIN, INT_MAX);
    printf("Limits of a short integer: [%d --> %d]\n", SHRT_MIN, SHRT_MAX);
    printf("Limits of a long integer: [%ld --> %ld]\n", LONG_MIN, LONG_MAX);

    printf("Integer (unsigned):\n");
    printf("Limits of an integer: [0 --> %u]\n", UINT_MAX);
    printf("Limits of a short integer: [0 --> %u]\n", USHRT_MAX);
    printf("Limits of a long integer: [0 --> %lu]\n", ULONG_MAX);

    printf("Floating types:\n");
    printf("Limits of a float: [%e --> %e] with %d digits precision\n",
        FLT_MIN,
        FLT_MAX,
        FLT_DIG);
    printf("Limits of a double: [%e --> %e] with %d digits precision\n",
        DBL_MIN,
        DBL_MAX,
        DBL_DIG);

    printf("Characters (ambiguous integer):\n");
    printf("Limits of a signed character: [%d --> %d]\n", CHAR_MIN, CHAR_MAX);
    printf("Limits of an unsigned character: [0 --> %d]\n", UCHAR_MAX);
}