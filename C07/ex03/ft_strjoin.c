/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:55:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/23 17:35:38 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_inception(int *strs_b_size, char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		strs_b_size += ft_strlen(strs[i]);
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new_str;
	int		strs_b_size;
	int		i;
	int		h;
	int		j;

	strs_b_size = ft_strlen_inception(&strs_b_size, strs, size);
	new_str = (char *)malloc(strs_b_size + ft_strlen(sep) * (size - 1) + 1);
	if (!new_str)
		return (0);
	if (size == 0)
		return (new_str);
	i = -1;
	h = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			new_str[h++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			new_str[h++] = sep[j++];
	}
	new_str[h] = '\0';
	return (new_str);
}
