/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:59:24 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/10 12:32:51 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writedigit(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

void	createaandprintarray(int n, int m)
{
	int	array[10];
	int	arrayiterate;

	arrayiterate = 0;
	while (arrayiterate < n + 1)
	{
		array[arrayiterate] = m % 10;
		arrayiterate++;
		m = m / 10;
	}
	while (n >= 0)
	{
		writedigit(array[n]);
		n--;
	}
}

void	ft_putnbr(int nb)
{
	int	cb;
	int	counter;

	cb = nb;
	counter = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
		return ;
	}
	if (nb < 10)
	{
		writedigit(nb);
		return ;
	}
	while (cb >= 10)
	{
		cb = cb / 10;
		counter = counter + 1;
	}
	createaandprintarray(counter, nb);
}
