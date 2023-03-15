/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:18 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/15 22:52:25 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\f' ||
			base [i] == '\r' || base[i] == '\t' || base[i] == '\v' ||
			base[i] == '\n' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	array_to_int(char *numberarray, int index, char *base, int sign)
{
	long	number;

	number = 0;
	while (numberarray[index])
	{
		number *= 10;
		number += numberarray[index] - is_alphanum(&numberarray[index]);
		index--;
	}
	return convert_to_base(number, base, sign);
}


int	convert_to_base(long nbr, char *original_base, int sign)
{
	int	number;
	int	r;
	int	power;
	int	base;

	number = 0;
	power = 1;
	base = ft_strlen(original_base);
	if (!base_check(original_base))
		return 0;
	if (sign> 0)
	{
		while (nbr > 0)
		{
			r = nbr % 10;
			number += r * power;
			power *= base;
			nbr /= 10;
		}
		return (number);
	}
	return (-convert_to_base(-nbr, original_base, 1));
}


/*
int	ft_putnb_base(int nbr, char *base)
{
	long	numberarray[32];
	int		index;
	long	nb;
	int		base_length;

	nb = nbr;
	base_length = ft_strlen(base);
	if (!base_check(base))
		return 0;
	if (nb < 0)
		nb = -nb;
	index = 0;
	while (nb != 0)
	{
		numberarray[index] = base[nb % base_length];
		nb = nb / base_length;
		index++;
	}
	return (array_to_int(numberarray, index-1));
}
*/

int	is_alphanum(char *a)
{
	if (*a >= 'A' && *a <= 'Z')
		return (65 - 10);
	if (*a >= 'a' && *a <= 'z')
		return (97 - 10);
	if (*a >= '0' && *a <= '9')
		return (48);
	return (0);
}

/*
int	ft_atoi_base(char *str, char *base)
{
	int		starting_index;
	int		ending_index;
	long	number;

	number = 0;
	starting_index = 0;
	while (is_alphanum(&str[starting_index]) == 0)
		starting_index++;
	ending_index = starting_index;
	while (is_alphanum(&str[ending_index]) != 0)
		ending_index++;
	while (starting_index < ending_index)
	{
		number *= 10;
		number += (str[starting_index]) - is_alphanum(&str[starting_index]);
		starting_index++;
	}
	while (starting_index > 0)
	{
		if (str[starting_index] == 45)
			number *= -1;
		starting_index--;
	}
	return (convert_to_base(number, base));
} */


int	ft_atoi_base(char *str, char *base)
{
	int		starting_index;
	int		i;
	char	*number;
	int		sign;

	starting_index = 0;
	while (is_alphanum(&str[starting_index]) == 0)
		starting_index++;
	i = 0;
	while (is_alphanum(&str[starting_index]) != 0)
	{
		number[i] = (str[starting_index]);
		i++;
		starting_index++;
	}
	sign = 1;
	while (starting_index > 0)
	{
		if (str[starting_index] == 45)
			sign *= -1;
		starting_index--;
	}
	return (convert_to_base(number, base, sign));
} 

void	ft_atoi_base_test(char *str, int i; char *base, int expected_number)
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
//	ft_atoi_base_test("\n \t\r \v \f++++--*/*/**,.fs", "/*", 43);
	// teste com bases octais
	printf("Bases octais:\n");
	ft_atoi_base_test("\n \t\r \v \f++-++--205,.fs", "01234567", -133);
//	ft_atoi_base_test("\n \t\r \v \f+-+++--fdd,.fs", "abcdefgh", -347);
	// teste com bases decimais
	printf("Bases decimais:\n");
	ft_atoi_base_test("\n \t\r \v \f++-++--2147483648,.fs", "0123456789", -2147483648);
//	ft_atoi_base_test("\n \t\r \v \f+-+++-+jjf,.fs", "abcdefghij", 995);
	// teste com bases hexadecimais
	printf("Bases hexadecimais:\n");
	ft_atoi_base_test("\n \t\r \v \f++-+-+--F0FA,.fs", "0123456789ABCDEF", 61690);
//	ft_atoi_base_test("\n \t\r \v \f+-+++-+ninc,.fs", "abcdefghijklmnop", 55506);
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



// Primeiro pegar na string e colocá-la numa array
// Inverter a array (?)
// Transformar a array num INT (como fazer com chars??)
// Transformar em base 2
// Return