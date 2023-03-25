/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:03:04 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/25 11:21:33 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int is_in_charset(char c, char *charset)
{
    int i;

    i = 0;
    while (charset[i])
        {
            if (c == charset[i])
                return (1);
			i++;
        }
    return (0);
}

int wordcount(char *str, char *charset)
{
	int wordcount;
	int wordbegin;
	int i;

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
	char 	*copy;
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
	
	printf("N is '%s'.\n", copy);
	return (copy);
}

char *populate_array(char** array, char *str, char *charset)
{
	int beg_ind;
	int end_ind;
	int arr_ind;
	int wordbegin;

	arr_ind = 0;
	end_ind = 0;
	wordbegin = 1;
	while (str[end_ind])
	{
		beg_ind = end_ind;
		if (is_in_charset(str[end_ind], charset) == 1)
		{
			array[arr_ind] = ft_strdup_ncpy(str[beg_ind], end_ind - beg_ind + 1);
			arr_ind++;
			wordbegin = 1;
		}
		if (is_in_charset(str[end_ind], charset) == 0 && wordbegin == 1)
			wordbegin = 0;
		end_ind++;
	}
}

char **ft_split(char *str, char *charset)
{
	int array_size;
	char **array;

	array_size = wordcount(str, charset) + 1;
	array = malloc(array_size * sizeof(char *));
	populate_array(array, str, charset);
	
}

////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int		str_n;
	char	*str;
	char	*sep;
	char	**strs;

	str = "yWfrONjnyyoiSQ5GYKxJ6NSlqrUtPkklcoKR fyy";

	sep = "ySzX";
	strs = ft_split(str, sep);
	/*
	str_n = 0;
	while (strs[str_n] != 0)
	{
		printf("[%d]: %s\n", str_n, strs[str_n]);
		str_n++;
	}
	free(strs);
	return (0);
	*/
}