#include "float.h"
#include "limits.h"
#include "stdio.h"

void typesLimits()
{
    printf("Integer (signed | default):\n");
    printf("\tLimits of an integer: [%d --> %d]\n", INT_MIN, INT_MAX);
    printf("\tLimits of a short integer: [%d --> %d]\n", SHRT_MIN, SHRT_MAX);
    printf("\tLimits of a long integer: [%ld --> %ld]\n", LONG_MIN, LONG_MAX);
    printf("\tUsing sizeof (in bites): [%lu]\n", sizeof(int));

    printf("Integer (unsigned):\n");
    printf("\tLimits of an integer: [0 --> %u]\n", UINT_MAX);
    printf("\tLimits of a short integer: [0 --> %u]\n", USHRT_MAX);
    printf("\tLimits of a long integer: [0 --> %lu]\n", ULONG_MAX);

    printf("Floating types:\n");
    printf("\tLimits of a float: [%e --> %e] with %d digits precision\n",
        FLT_MIN,
        FLT_MAX,
        FLT_DIG);
    printf("\tUsing sizeof (in bites): [%lu]\n", sizeof(float));
    printf("\tLimits of a double: [%e --> %e] with %d digits precision\n",
        DBL_MIN,
        DBL_MAX,
        DBL_DIG);
    printf("\tUsing sizeof (in bites): [%lu]\n", sizeof(double));

    printf("Characters (ambiguous integer):\n");
    printf("\tLimits of a signed character: [%d --> %d]\n", CHAR_MIN, CHAR_MAX);
    printf("\tLimits of an unsigned character: [0 --> %d]\n", UCHAR_MAX);
    printf("\tUsing sizeof (in bites): [%lu]\n", sizeof(char));
}