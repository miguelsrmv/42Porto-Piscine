#include "ft_abs.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    int n = ABS(atoi(argv[1]));
    printf("%i\n", n);
}