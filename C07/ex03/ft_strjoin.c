/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:55:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/28 15:13:42 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strlen_inception(int *overall_size, char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		*overall_size += ft_strlen(strs[i]);
		i++;
	}
}

void	populate_array(int size, char **strs, char *sep, char *new_str)
{
	int	i;
	int	h;
	int	j;

	i = 0;
	h = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			new_str[h++] = strs[i][j++];
		j = 0;
		while (sep[j] && i + 1 < size)
			new_str[h++] = sep[j++];
		i++;
	}
	new_str[h] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new_str;
	int		overall_size;

	overall_size = 0 + ft_strlen(sep) * (size - 1) + 1;
	ft_strlen_inception(&overall_size, strs, size);
	if (size == 0)
	{
		new_str = malloc(1);
		if (!new_str)
			return (0);
		return (new_str);
	}
	new_str = malloc(overall_size * sizeof(char));
	if (!new_str)
		return (0);
	populate_array(size, strs, sep, new_str);
	return (new_str);
}
