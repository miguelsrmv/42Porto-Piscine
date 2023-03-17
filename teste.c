#include <unistd.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    int i = 0;
    int j = 0;
    printf("Argc = %i\n", argc);

    while (i < argc)
    {
        while (argv[i][j])
        {
            write (1, &argv[i][j], 1);
            j++;
        }
        j = 0;
        i++;
        printf("\n");
    }
}

/*
{'.', 'a', 'b', 'c', 'd'}
*/
