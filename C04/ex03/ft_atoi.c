/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:28:15 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/25 17:22:59 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 0;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign++;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10;
		result = result + *str - 48;
		++str;
	}
	if ((sign % 2) == 0)
		return (result);
	return (-result);
}
