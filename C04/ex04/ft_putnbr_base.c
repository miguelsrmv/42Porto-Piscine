/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:26:57 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/15 17:22:07 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	numberarray[32];
	int		index;
	long	nb;

	nb = nbr;
	if (base_check(base) == 0)
		return ;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	index = 0;
	while (nb != 0)
	{
		numberarray[index] = base[(nb % ft_strlen(base))];
		nb = nb / ft_strlen(base);
		index++;
	}
	while (index >= 0)
	{
		ft_putchar(numberarray[index - 1]);
		index--;
	}
}
