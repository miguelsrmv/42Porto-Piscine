/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:36:37 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/21 16:40:24 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char    *ft_strdup(char *src)
{
    int i;
    char *n;

    while (src[i])
        i++;
    n = malloc(i);
    ft_strcpy(n, src);
    return(n);
}

int main (void)
{
    char* source = "Era o que me faltava";
    ft_strdup(source);
}