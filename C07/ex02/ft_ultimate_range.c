/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:43:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/23 17:35:20 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max, int *array)
{
	int	i;

	if (max < min)
		return (0);
	i = 0;
	while (min + i != max)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;

	if (min > max)
	{
		array = NULL;
		return (0);
	}
	array = (int *)malloc((max - min) * 4);
	if (!array)
		return (-1);
	*range = ft_range(min, max, array);
	printf("Max: %i, Min: %i\n", max, min);
	return (max - min);
}
