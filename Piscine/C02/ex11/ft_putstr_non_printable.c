/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:11:31 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/16 11:30:22 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_print(char c)
{
	if (c > 31 && c < 127)
		return (0);
	else
		return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_print(str[i]) == 0)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			if (str[i] < 0)
				j = str[i] + 256;
			else
				j = str[i];
			ft_putchar("0123456789abcdef"[j / 16]);
			ft_putchar("0123456789abcdef"[j % 16]);
		}
		i++;
	}
}
