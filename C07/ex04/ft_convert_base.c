/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:20:28 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/27 11:54:33 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		check_base(char *base);
void	whitespace_and_sign(int *i, int *sign, char *str);
int		is_number_in_base(char c, char *base);
int		convert_int_from_base(char c, char *base);

int	ft_atoi_to_decimal(char *str, char *base)
{
	int		i;
	int		result;
	int		base_length;
	int		sign;

	base_length = 0;
	result = 0;
	sign = 1;
	base_length = ft_strlen(base);
	whitespace_and_sign(&i, &sign, str);
	while (str[i] && is_number_in_base(str[i], base))
	{
		result *= base_length;
		result += convert_int_from_base(str[i], base);
		i++;
	}
	result *= sign;
	return (result);
}

void	ft_int_to_array_as_base(int nbr, char *base, char *array, int *index)
{
	int		length;
	long	n;

	length = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		n = n * (-1);
		array[0] = '-';
		++*index;
	}
	if (n < length)
	{
		array[*index] = (base[n]);
		++*index;
	}
	if (n >= length)
	{
		ft_int_to_array_as_base((n / length), base, array, index);
		ft_int_to_array_as_base((n % length), base, array, index);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal_num;
	char	*numberarray;
	int		index;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (0);
	decimal_num = ft_atoi_to_decimal(nbr, base_from);
	if (!decimal_num)
		return (NULL);
	index = 0;
	numberarray = malloc(1 + 32 * sizeof(char) + 1);
	if (!numberarray)
		return (0);
	ft_int_to_array_as_base(decimal_num, base_to, numberarray, &index);
	numberarray[index] = '\0';
	return (numberarray);
}
