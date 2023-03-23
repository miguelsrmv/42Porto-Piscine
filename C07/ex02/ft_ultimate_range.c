/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:43:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/23 12:53:14 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	if (max < min)
		return (0);
	array = malloc((max - min) * 4);
	i = 0;
	while (min + i != max)
	{
		array[i] = min + i;
		i++;
	}
	return(array);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	*range = ft_range(min, max);
	if (*range == NULL)
		return (0);
	return (max - min);
}
