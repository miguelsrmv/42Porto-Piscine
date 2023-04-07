/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:04:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/11 19:02:54 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	iterate;

	iterate = 0;
	while (iterate < (size / 2))
	{
		ft_swap(&tab[iterate], &tab[size - 1 - iterate]);
		iterate++;
	}
}
