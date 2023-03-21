/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:28:15 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/21 12:10:25 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	whitespace_or_signs(char *a)
{
	if (*a == ' ' || *a == '\f' || *a == '\n' || *a == '\r' || *a == '\t'
		|| *a == '\v' || *a == '+' || *a == '-')
		return (1);
	return (0);
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
	while (str[index] >= '0' && str[index] <= '9')
	{
		number *= 10;
		number += (str[index] - '0');
		index++;
	}
	number = number * sign;
	return (number);
}
