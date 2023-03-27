/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:03:04 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/27 11:50:30 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	wordcount(char *str, char *charset)
{
	int	wordcount;
	int	wordbegin;
	int	i;

	wordbegin = 1;
	wordcount = 0;
	i = 0;
	while (str[i])
	{
		if (is_in_charset(str[i], charset) == 1)
			wordbegin = 1;
		if (is_in_charset(str[i], charset) == 0 && wordbegin == 1)
		{
			wordbegin = 0;
			wordcount++;
		}
		i++;
	}
	return (wordcount);
}

char	*ft_strdup_ncpy(char *src, int length)
{
	char	*copy;
	int		i;

	copy = (char *)malloc(length + 1);
	i = 0;
	while (src[i] != '\0' && i < length)
	{
		copy[i] = src[i];
		i++;
	}
	while (i < length)
	{
		copy[i] = '\0';
		i++;
	}
	return (copy);
}

void	populate_array(char **array, char *str, char *charset, int arr_ind)
{
	int	beg_ind;
	int	end_ind;
	int	wordbegin;

	end_ind = 0;
	wordbegin = 1;
	while (is_in_charset(str[end_ind], charset) == 1)
			end_ind++;
	beg_ind = end_ind;
	while (str[end_ind])
	{
		if (is_in_charset(str[end_ind], charset) == 1 && wordbegin == 0)
		{
			array[arr_ind] = ft_strdup_ncpy(&str[beg_ind], end_ind - beg_ind);
			arr_ind++;
			while (is_in_charset(str[end_ind], charset) == 1)
				end_ind++;
			wordbegin = 1;
			beg_ind = end_ind;
		}
		else
			wordbegin = 0;
		end_ind++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int		array_size;
	char	**array;
	int		arr_ind;

	arr_ind = 0;
	array_size = wordcount(str, charset) + 1;
	array = malloc(array_size * sizeof(char *));
	populate_array(array, str, charset, arr_ind);
	array[array_size - 1] = '\0';
	return (array);
}
