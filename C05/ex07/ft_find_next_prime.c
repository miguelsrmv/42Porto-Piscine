/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:57:18 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/21 14:40:42 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = nb - 1;
	while (i > 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	nb++;
	while (ft_is_prime(nb) != 1)
	{
		nb++;
	}
	return (nb);
}
