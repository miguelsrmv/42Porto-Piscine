/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:59:24 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/16 18:32:39 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)//// TERMINAR AQUI!!!
		
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
}

#include <stdio.h>

int main (void)
{
	int a = 1;
	int b = -1;
	int c = 0;
	int d = 10;
	int e = -10;
	int f = 2147483647;
	int g = -2147483648;

	ft_putnbr(a);
	printf("\n");
	ft_putnbr(b);
	printf("\n");
	ft_putnbr(c);
	printf("\n");
	ft_putnbr(d);
	printf("\n");
	ft_putnbr(e);
	printf("\n");
	ft_putnbr(f);
	printf("\n");
	ft_putnbr(g);
}