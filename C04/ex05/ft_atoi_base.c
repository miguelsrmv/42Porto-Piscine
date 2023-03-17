/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:18 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/17 10:07:31 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ascii_table_and_whitespace(char *a)
{
	if (*a >= 'A' && *a <= 'Z')
		return (65 - 10);
	if (*a >= 'a' && *a <= 'z')
		return (97 - 10);
	if (*a >= '0' && *a <= '9')
		return (48);
	if (*a == '\f' || *a == '\r' || *a == '\t'
		|| *a == '\v' || *a == '\n' || *a == ' '
		|| *a == '+' || *a == '-')
		return (1);
	return (0);
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
		if (ascii_table_and_whitespace(&base[i]) == 1)
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

int	convert_number(char *numberarray, char *base, int sign)
{
	int	i;
	int	number;
	int	len_numberarray;
	int	len_base;

	if (base_check(base) == 0)
		return (0);
	len_numberarray = ft_strlen(numberarray);
	len_base = ft_strlen(base);
	number = 0;
	i = 0;
	while (i < len_numberarray)
	{
		number *= len_base;
		number += numberarray[i] - ascii_table_and_whitespace(&numberarray[i]);
		i++;
	}
	number = number * sign;
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int		starting_index;
	int		sign;
	int		i;
	char	number[10];
	int		result;

	starting_index = 0;
	sign = 1;
	while (ascii_table_and_whitespace(&str[starting_index]) <= 1)
	{
		if (str[starting_index] == '-')
			sign *= -1;
		starting_index++;
	}
	i = 0;
	while (ascii_table_and_whitespace(&str[starting_index]) > 1)
	{
		number[i] = (str[starting_index]);
		i++;
		starting_index++;
	}
	number[i] = '\0';
	result = (convert_number(number, base, sign));
	return (result);
}
