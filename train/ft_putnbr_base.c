#include <stdio.h>
#include <unistd.h>
#include <limits.h>


int checkbase(char *base)
{
    int len;
    int repeatcheck;

    len = 0;
    while (base[len])
        {
            repeatcheck = len + 1;
            while (base[repeatcheck])
            {
                if (base[repeatcheck] == base[len] || base[repeatcheck] == '+' || base[repeatcheck] == '-' || base[repeatcheck] == '\n' || base[repeatcheck] == '\t' || base[repeatcheck] == '\r' || base[repeatcheck] == '\v' || base[repeatcheck] == '\f' || base[repeatcheck] == ' ')
                    return (0);
                repeatcheck++;
            }
            len++;
        }
    if (len < 2)
        return (0);
    return (1);
}

void ft_putnbr_base(int nbr, char *base)
{
    if (checkbase(base) == 0)
        return ;
    
    int base_len;
    base_len = 0;

    while (base[base_len])
        base_len++;
    
    long n;
    n = nbr;
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }

    char c;
    if (n >= base_len)
    {
        ft_putnbr_base(n / base_len, base);
        n = n % base_len;
    }
    if (n < base_len)
    {
        c = base[n];                                
        write(1, &c, 1);
    }
}


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	// base binaria
	printf("Bases binarias, n = 47. \"01\" e \"\\/\"\n");
	ft_putnbr_base(47, "01");
	ft_putchar('\n');
	printf("Esperado: 101111\n");
	ft_putnbr_base(47, "\\/");
	ft_putchar('\n');
	printf("Esperado: /\\////\n");
	// base 5
	printf("Bases 5, n = 36. \"01345\" e \"sd2ek\"\n");
	ft_putnbr_base(36, "01345");
	ft_putchar('\n');
	printf("Esperado: 131\n");
	ft_putnbr_base(36, "sd2ek");
	ft_putchar('\n');
	printf("Esperado: d2d\n");
	// base 10
	printf("Bases 10, n = %d. \"0123456789\" e \",.;\\][{}@#\"\n", INT_MIN);
	ft_putnbr_base(INT_MIN, "0123456789");
	ft_putchar('\n');
	printf("Esperado: -2147483648\n");
	ft_putnbr_base(INT_MIN, ",.;\\][{}@#");
	ft_putchar('\n');
	printf("Esperado: -;.]}]@\\{]@\n");
	// base 16
	printf("Bases 16, n = -65040. \"0123456789ABCDEF\" e \"jdlskmnMKZxVuzfa\"\n");
	ft_putnbr_base(-65040, "0123456789ABCDEF");
	ft_putchar('\n');
	printf("Esperado: -FE10\n");
	ft_putnbr_base(-65040, "jdlskmnMKZxVuzfa");
	ft_putchar('\n');
	printf("Esperado: -afdj\n");
	// base 0 e base 1, nao pode aparecer nada
	printf("Bases 0 e 1, nao deve aparecer nada, n = 256.\n");
	ft_putnbr_base(-29092, "0");
	ft_putnbr_base(-29092, "");
	return (0);
}
