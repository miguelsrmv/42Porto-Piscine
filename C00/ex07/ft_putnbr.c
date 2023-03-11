/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:59:24 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/11 19:56:17 by mde-sa--         ###   ########.fr       */
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
	int	array[15];
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

void	invert(int *n)
{
	*n *= -1;
	write(1, "-", 1);
}

void	ft_putnbr(int nb)
{
	int	cb;
	int	counter;

	if (nb == -2147483648)
	{
		write(1, "-", 1);
		createaandprintarray(8, 214748364);
		writedigit(8);
		return ;
	}
	if (nb < 0)
		invert(&nb);
	cb = nb;
	if (cb < 10)
	{
		writedigit(cb);
		return ;
	}
	counter = 0;
	while (cb >= 10)
	{
		cb = cb / 10;
		counter++;
	}
	createaandprintarray(counter, nb);
}
