

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
    if (len == 0)
        return (0);
    return (1);
}

int is_in_base(char c, char *base)
{
    int i;
    i = 0;
    while (base[i])
        {
            if (base[i] == c)
                return(i);
            i++;
        }
    return(-1);
}

int ft_atoi_base(char *str, char *base)
{
    if (checkbase(base) == 0)
        return(0);

    int i;
    i = 0;

    int base_len;
    base_len = 0;

    while (base[base_len])
        base_len++;

    int signal;
    signal = 1;

    int n;
    n = 0;

    while (str[i])
    {
        if (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
            i++;
        else if (str[i] == '-' || str[i] == '+')
        {
            if (str[i] == '-')
                signal *= -1;
            i++;
        }
        else
            break;
    }

    while(is_in_base(str[i], base) >= 0)
    {
        n *= base_len;
        n += is_in_base(str[i], base);
        i++;
    }
    return (n * signal);
}


#include <stdio.h>

void	ft_atoi_base_test(char *str, char *base, int expected_number)
{
	int ft_buff;

	ft_buff = ft_atoi_base(str, base);
	if (ft_buff != expected_number)
		printf("> KO, expected: %d got: %d\n", expected_number, ft_buff);
	else
		printf("> OK, result: %d\n", ft_buff);
}

int	main(void)
{
	// teste com bases binarias
	printf("Bases binarias:\n");
	ft_atoi_base_test("\n \t\r \v \f++++--1000,.fs", "01", 8);
	ft_atoi_base_test("\n \t\r \v \f++++--*/*/**,.fs", "/*", 43);
	// teste com bases octais
	printf("Bases octais:\n");
	ft_atoi_base_test("\n \t\r \v \f++-++--205,.fs", "01234567", -133);
	ft_atoi_base_test("\n \t\r \v \f+-+++--fdd,.fs", "abcdefgh", -347);
	// teste com bases decimais
	printf("Bases decimais:\n");
	ft_atoi_base_test("\n \t\r \v \f++-++--2147483648,.fs", "0123456789", -2147483648);
	ft_atoi_base_test("\n \t\r \v \f+-+++-+jjf,.fs", "abcdefghij", 995);
	// teste com bases hexadecimais
	printf("Bases hexadecimais:\n");
	ft_atoi_base_test("\n \t\r \v \f++-+-+--F0FA,.fs", "0123456789ABCDEF", 61690);
	ft_atoi_base_test("\n \t\r \v \f+-+++-+ninc,.fs", "abcdefghijklmnop", 55506);
	// teste com bases invalidas
	printf("Bases invalidas:\n");
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "", 0);
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0", 0);
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123456678", 0);
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123\n", 0);
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123\v", 0);
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123\t", 0);
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123\f", 0);
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123\r", 0);
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123 ", 0);
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123+", 0);
	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123-", 0);
}
