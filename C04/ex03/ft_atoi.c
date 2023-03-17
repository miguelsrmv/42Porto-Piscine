/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:28:15 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/17 11:57:35 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	whitespace_or_signs(char *a)
{
	if (*a == ' ' || *a == '\f' || *a == '\n' || *a == '\r'|| *a == '\t' 
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
	int		starting_index;
	int		ending_index;
	int		number;
	int		sign;

	number = 0;
	starting_index = 0;
	sign = 1;
	while (whitespace_or_signs(&str[starting_index]) == 1)
	{
		if (str[starting_index] == '-')
			sign *= -1;
		starting_index++;
	}
	ending_index = starting_index;
	while (str[ending_index] >= '0' && str[ending_index] <= '9')
		ending_index++;
	if (sign == -1 && ft_strncmp(&str[starting_index], "2147483648", 10) == 0)
		return (-2147483648);
	while (starting_index < ending_index)
	{
		number *= 10;
		number += (str[starting_index] - '0');
		starting_index++;
	}
	number = number * sign;
	return (number);
}


#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(char *str);

void	ft_atoi_like_test(char *str)
{
	int buff;
	int ft_buff;

	buff = atoi(str);
	ft_buff = ft_atoi(str);
	if (buff != ft_buff)
		printf("> KO, invalid int value returned. expected: %d got: %d\n", buff, ft_buff);
	else
		printf("> OK. result: %d\n", ft_buff);
}

void	ft_atoi_unlike_test(char *str, int expected_result)
{
	int ft_buff;

	ft_buff = ft_atoi(str);
	if (ft_buff != expected_result)
		printf("> KO, invalid int value returned expected: %d got: %d\n", expected_result, ft_buff);
	else
		printf("> OK, result: %d\n", ft_buff);
}

int		main(void)
{
	char *str;

	// quando o comportamento e igual ao de atoi
	str = " \n \t \r \v +1234567asd";
	ft_atoi_like_test(str);
	str = " \n \t\f\r \v -1234b67asd";
	ft_atoi_like_test(str);
	// quando o comportamento e diferente ao de atoi
	str = " \n \t \r \v --+-+-+-2147483648asd";
	ft_atoi_unlike_test(str, -2147483648);
	str = " \n \t\f\r \v -++-+-+2147483648asd";
	ft_atoi_unlike_test(str, -2147483648);
	str = " \n \t\f\r \v -++-+-++6535154asd";
	ft_atoi_unlike_test(str, -6535154);
	str = " \n \t\f\r \v -++-+++4bgg67asd";
	ft_atoi_unlike_test(str, 4);
	str = " \n \t\f\r \v -++-+++-1000234b67asd";
	ft_atoi_unlike_test(str, -1000234);
	str = " \n \t\f\r \v -+---3488932hfhb67asd";
	ft_atoi_unlike_test(str, 3488932);
	str = " \n \t\f\r \v -++--45721234b67asd";
	ft_atoi_unlike_test(str, -45721234);
	str = " \n \t\f\r \v --+--5651234b67as555d";
	ft_atoi_unlike_test(str, 5651234);
	str = " \n \t\f\r \v -+++5hgchg17a52d";
	ft_atoi_unlike_test(str, -5);

	return (0);
}