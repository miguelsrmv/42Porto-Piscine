#include <stdio.h>

int power(int n);

int main (void)
{
    printf("%i", power(3));
}

int power (n)
{
    if (n == 0)
        return 1;
    else
        return 10*(power(n-1))
}