/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:11:07 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/13 13:59:03 by mde-sa--         ###   ########.fr       */
=======
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:11:07 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/11 19:10:24 by mde-sa--         ###   ########.fr       */
>>>>>>> 429154f1cfaaeb622f35cb0ffaa2fc6f24d66c44
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
