/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:18:05 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/21 12:01:37 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	copy;

	copy = nb;
	i = 1;
	if (nb <= 0)
		return (0);
	while (i < copy)
	{
		nb *= (copy - i);
		i++;
	}
	return (nb);
}
