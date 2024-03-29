/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:41:46 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/05/28 21:42:12 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	iterate;

	iterate = 0;
	while (size > 1)
	{
		while (iterate < size - 1)
		{
			if (tab[iterate] > tab[iterate + 1])
				ft_swap(&tab[iterate], &tab[iterate + 1]);
			iterate++;
		}
		iterate = 0;
		size--;
	}
}
