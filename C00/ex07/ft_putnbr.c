/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:59:24 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/09 13:09:08 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	cb;
	int	counter;

	cb = nb;
	counter = 0;
	while (cb > 10)
	{
		cb = cb / 10;
		counter = counter + 1;
	}
	writedigit(cb);
	if (counter > 0)
	{
		nb = nb - cb * poweroften(counter);
		ft_putnbr(nb);
	}
}

void	writedigit(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

int	poweroften(int e)
{
	if (e == 0)
	{
		return (1);
	}
	else
	{
		return (10 * poweroften(e - 1));
	}
}
