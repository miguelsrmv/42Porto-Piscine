/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:32:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/14 19:09:58 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;

	i = 0;
	if (size != 0)
	{
		while ((i < (size - 1)) && (src[i] != "\0"))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (size);
	}
	return (size);
}
