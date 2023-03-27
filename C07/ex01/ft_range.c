/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:25:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/27 09:53:41 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	if (min >= max)
		return (NULL);
	array = (int *)malloc((max - min) * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (min + i != max)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
