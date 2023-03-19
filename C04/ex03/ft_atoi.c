/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:28:15 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/19 14:49:48 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	whitespace_or_signs(char *a)
{
	if (*a == ' ' || *a == '\f' || *a == '\n' || *a == '\r' || *a == '\t'
		|| *a == '\v' || *a == '+' || *a == '-')
		return (1);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(char *str)
{
	int		index;
	int		number;
	int		sign;

	number = 0;
	index = 0;
	sign = 1;
	while (whitespace_or_signs(&str[index]) == 1)
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	if (sign == -1 && ft_strncmp(&str[index], "2147483648", 10) == 0)
		return (-2147483648);
	while (str[index] >= '0' && str[index] <= '9')
	{
		number *= 10;
		number += (str[index] - '0');
		index++;
	}
	number = number * sign;
	return (number);
}
