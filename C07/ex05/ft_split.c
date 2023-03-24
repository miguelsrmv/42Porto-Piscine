/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:03:04 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/24 13:04:54 by mde-sa--         ###   ########.fr       */
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

int is_in_charset(char c, char *charset)
{
    int i;

    i = 0;
    while (charset[i])
        {
            if (charset[i] == c)
                return (1);
			i++;
        }
    return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *src, int i)
{
	char *n;

	n = (char *)malloc(i + 1);
	ft_strncpy(n, src, i);
	return (n);
}

char **ft_split(char *str, char *charset)
{
    int		i;
    int		j;
	int 	h;
	char	*substring;
	char	*array[10000];

    i = 0;
	j = i;
	h = 0;
    while (str[i])
    {
        if (is_in_charset(str[i], charset) == 1 || str[i] == '\0')
		{
			substring = ft_strdup(&str[j], i - j);
			array[h] = substring;
			j = ++i;
			h++;
		}
        i++;
	}
	return (array);
}


#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int		str_n;
	char	*str;
	char	*sep;
	char	**strs;

	str = "WfrONjnyoiSQ5GYKxJ6NSlqrUtPkklcoKR f";
	sep = "ySzX";
	strs = ft_split(str, sep);
	str_n = 0;
	while (strs[str_n] != 0)
	{
		printf("[%d]: %s\n", str_n, strs[str_n]);
		str_n++;
	}
	free(strs);
	return (0);
}