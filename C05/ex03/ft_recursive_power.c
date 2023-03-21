/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:26:19 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/21 10:36:03 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}
