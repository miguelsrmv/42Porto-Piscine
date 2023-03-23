/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:20:28 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/23 11:56:49 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int		i;
	int		j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == '\f'
			|| base[i] == '\t' || base[i] == ' ' || base[i] == '\n'
			|| base[i] == '\r' || base[i] == '\v')
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

void	whitespace_and_sign(int *i, int *sign, char *str)
{
	int		j;

	j = 0;
	while (str[j] == '\f' || str[j] == '\t' || str[j] == ' '
		|| str[j] == '\n' || str[j] == '\r' || str[j] == '\v')
		j++;
	while (str[j] && (str[j] == '+' || str[j] == '-'))
	{
		if (str[j] == '-')
			*sign = -(*sign);
		j++;
	}
	*i = j;
}

int	is_number_in_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != c && base[i])
		i++;
	if (base[i] == c)
		return (1);
	return (0);
}

int	convert_int_from_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

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

void ft_int_to_array_as_base(int nbr, char* base, char* numberarray, int *index)
{
	int		length;
	long	n;

	length = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		n = n * (-1);
		numberarray[0] = '-';
		++*index;
	}
	if (n < length)
	{
		numberarray[*index] = (base[n]);
		++*index;
	}
	if (n >= length)
	{
		ft_int_to_array_as_base((n / length), base, numberarray, index);
		ft_int_to_array_as_base((n % length), base, numberarray, index);
	}
}


char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		basecheck;
	int		decimal_num;
	char	*numberarray;
	int		index;

	basecheck = check_base(base_from);
	if (basecheck == 0)
		return (0);
	decimal_num = ft_atoi_to_decimal(nbr, base_from);
	index = 0;
	numberarray = malloc(32);
	ft_int_to_array_as_base(decimal_num, base_to, numberarray, &index);
	return (numberarray);
}

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char nbr[] = "-2147483648";
	char base_to[] = "0";
	char base_from[] = "0123456789";
	char *res;

	res = ft_convert_base(nbr, base_from, base_to);
	if (res == NULL)
		return (1);
	printf("%s\n", res);
	free(res);
	return (0);
}