/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:53:31 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/10 11:08:00 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_number(int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write(1, "0", 1);
		write(1, &c, 1);
	}
	else
	{
		c = (n / 10) + 48;
		write(1, &c, 1);
		c = (n % 10) + 48;
		write(1, &c, 1);
	}
}

void	ft_print_comb2(void)
{
	int	i[2];

	i[0] = 0;
	i[1] = 1;
	while (i[0] < 99)
	{
		while (i[1] < 100)
		{
			write_number(i[0]);
			write(1, " ", 1);
			write_number(i[1]);
			if ((i[0] == 98) && (i[1] == 99))
				return ;
			write (1, ", ", 2);
			i[1] = i[1] + 1;
		}
		i[0] = i[0] + 1;
		i[1] = i[0] + 1;
	}
}
