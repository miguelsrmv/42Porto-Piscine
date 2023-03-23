/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:25:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/23 12:51:04 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*array;

	if (max < min)
		return (0);
	array = (int*)malloc((max - min) * 4);
	i = 0;
	while (min + i != max)
	{
		array[i] = min + i;
		i++;
	}
	return(array);
}
