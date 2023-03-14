/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:11:31 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/14 19:10:52 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	*convert_to_hex(char dec_c, char *hex_c[])
{
	int		remainder;
	int		i;

	while (dec_c != 0)
	{
		if (remainder < 16)
			hex_c[1] = 48;
		remainder = dec_c % 16;
		if (remainder < 10)
			remainder = remainder + 48;
		else
			remainder = remainder + 87;
		hex_c[i] = remainder;
		i++;
		dec_c = dec_c / 16;
	}
	swap(&hex_c[0], &hex_c[1]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*unprintable_char[2];

	i = 0;
	while (str[i])
	{
		if ((str[i] > 31) && str[i] < 127)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 2);
			convert_to_hex(str[i], &unprintable_char);
			write(1, &unprintable_char[0], 1);
			write(1, &unprintable_char[1], 1);
		}
		i++;
	}
}

#include <unistd.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char str[] = {'0', '1', 2, 30, 16, '4', 'a', 19, 'C'};

	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	return (0);
}