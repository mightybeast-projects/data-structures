#include "stdio.h"

#define YEAR 2025
#define DEBUG 1
#define ADD(x, y) (x + y)

void preprocessorTrash(void)
{
    printf("MightyBeastLabs (c) %d.\n", YEAR);
    printf("Compiled on %s at %s\n", __DATE__, __TIME__);
    printf("Function called: %s\n", __func__);

#if DEBUG
    printf("Debug mode enabled.\n");
#else
    printf("Debug mode disabled.\n");
#endif

#ifdef ADD
    printf("ADD macro defined.\n");
    printf("ADD macro (10 + 5): %d\n", ADD(10, 5));
#else
    printf("ADD macro is not defined.\n");
#endif

#ifndef YEAR
#error Year is not defined.
#endif
}