#include "float.h"
#include "limits.h"
#include "stdio.h"

void typesLimits()
{
    printf("Integer (signed | default):\n");
    printf("\tLimits of an integer: [%d --> %d] | [%ld bytes]\n",
        INT_MIN,
        INT_MAX,
        sizeof(int));
    printf("\tLimits of a short integer: [%d --> %d] | [%ld bytes]\n",
        SHRT_MIN,
        SHRT_MAX,
        sizeof(short int));
    printf("\tLimits of a long integer: [%ld --> %ld] | [%ld bytes]\n",
        LONG_MIN,
        LONG_MAX,
        sizeof(long int));

    printf("Integer (unsigned):\n");
    printf("\tLimits of an integer: [0 --> %u] | [%ld bytes]\n",
        UINT_MAX,
        sizeof(unsigned int));
    printf("\tLimits of a short integer: [0 --> %u] | [%ld bytes]\n",
        USHRT_MAX,
        sizeof(unsigned short int));
    printf("\tLimits of a long integer: [0 --> %lu] | [%ld bytes]\n",
        ULONG_MAX,
        sizeof(unsigned long int));

    printf("Floating types:\n");
    printf("\tLimits of a float: [%e --> %e] | [%ld bytes] with %d digits "
           "precision\n",
        FLT_MIN,
        FLT_MAX,
        sizeof(float),
        FLT_DIG);
    printf("\tLimits of a double: [%e --> %e] | [%ld bytes] with %d digits "
           "precision\n",
        DBL_MIN,
        DBL_MAX,
        sizeof(double),
        DBL_DIG);

    printf("Character (ambiguous integer):\n");
    printf("\tLimits of a signed character: [%d --> %d] | [%ld bytes]\n",
        CHAR_MIN,
        CHAR_MAX,
        sizeof(char));
    printf("\tLimits of an unsigned character: [0 --> %d] | [%ld bytes]\n",
        UCHAR_MAX,
        sizeof(unsigned char));
}