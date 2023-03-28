/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:43:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/28 09:39:06 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*buffer;

	if (min >= max)
		return (0);
	buffer = malloc((max - min) * sizeof(int));
	if (!buffer)
		return (-1);
	i = 0;
	*range = buffer;
	while (min + i != max)
	{
		buffer[i] = min + i;
		i++;
	}
	return (max - min);
}
