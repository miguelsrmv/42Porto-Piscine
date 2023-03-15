/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:11:31 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/15 14:44:07 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert_to_hex(char dec_c, char *hex)
{
	int		remainder;
	int		quotient;
	int		i;

	quotient = dec_c;
	i = 1;
	hex[0] = '0';
	hex[1] = '0';
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			remainder += 48;
		else
			remainder += 87;
		hex[i] = remainder;
		i--;
		quotient = quotient / 16;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	unprintable_char[2];

	i = 0;
	while (str[i])
	{
		if ((str[i] > 31) && str[i] < 127)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			convert_to_hex(str[i], &unprintable_char[0]);
			write(1, &unprintable_char[0], 1);
			write(1, &unprintable_char[1], 1);
		}
		i++;
	}
}
