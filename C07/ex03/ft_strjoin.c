/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:55:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/22 10:17:54 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*newstring;
	int		i;
	int		j;
	int		h;

	newstring = malloc (ft_strlen(*strs) * size + ft_strlen(sep) * (size - 1) + 1);
	i = 0;
	h = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			newstring[h++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			newstring[h++] = sep[j++];
		i++;
	}
	newstring[h] = '\0';
	return (newstring);
}
