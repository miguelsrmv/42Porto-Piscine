/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:32:08 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/16 12:11:32 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char *str;
	char *to_find;
	char *buff;
	char *ft_buff;

	str = strcpy(calloc(11, sizeof(char)), "alo galera");
	to_find = strcpy(calloc(7, sizeof(char)), "galera");
	buff = strstr(str, to_find);
	ft_buff = ft_strstr(str, to_find);
	if (buff != ft_buff)
		printf("[1] KO, substrings don't match(expected:%s, got:%s)\n", buff, ft_buff); 
	else
		printf("[1] OK. expected: %s result: %s\n", buff, ft_buff);
	str = strcpy(calloc(11, sizeof(char)), "camone");
	to_find = strcpy(calloc(7, sizeof(char)), "cam.");
	buff = strstr(str, to_find);
	ft_buff = ft_strstr(str, to_find);
	if (buff != ft_buff)
		printf("[2] KO, substrings don't match(expected:%s, got:%s)\n", buff, ft_buff); 
	else
		printf("[2] OK. expected: %s result: %s\n", buff, ft_buff);
	str = strcpy(calloc(11, sizeof(char)), "alo galera");
	to_find = strcpy(calloc(1, sizeof(char)), "");
	buff = strstr(str, to_find);
	ft_buff = ft_strstr(str, to_find);
	if (buff != ft_buff)
		printf("[2] KO, substrings don't match(expected:%s, got:%s)\n", buff, ft_buff); 
	else
		printf("[2] OK. expected: %s result: %s\n", buff, ft_buff);
	return (0);
}


int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && i < n)
		i++;
	return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		to_find_size;

	i = 0;
	to_find_size = 0;
	while (to_find[to_find_size])
		to_find_size++;
	if (to_find_size == 0)
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			if (ft_strncmp(&str[i], to_find, to_find_size) == 0)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
