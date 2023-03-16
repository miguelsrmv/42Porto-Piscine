/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:28:04 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/16 15:36:41 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_size;
	unsigned int	dest_size;
	unsigned int	src_i;
	unsigned int	dest_i;

	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);

	if (size <= dest_size)
		return (src_size + size);
	src_i = 0;
	dest_i = dest_size;
	while (src[src_i] && (src_i + dest_size) < size - 1)
	{
		dest[dest_i] = src[src_i];				
		dest_i++;
		src_i++;
	}
	dest[dest_i] = '\0';
	return (dest_size + ft_strlen(&src[src_i]));
}




#include <stdio.h>

int main (void)
{
	char source[7] = {'C', 'A', 'O', 'A', 'B', 'C', '\0'}; 
	int size = 6;
	char dest[6];
	ft_strlcat(dest, source, size);

	int i = 0;
	while (i < size)
	{
		printf("%c,", dest[i]);
		i++;
	}
		
}

/* 
1.Take the full of the size of the buffer and guarantee to nul/terminate
result if size > 0 or if there is one free byte in dest.
2. A byte for null should be included in size
3. src MUST be nul-terminated
4. Copies up to size - 1 character
5. Return total length of src
6. Se nao encontrar nul apos size characters, o comprimento da string e size e dest
NAO tem nul */