/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:11:52 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/14 15:29:30 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	char *pointer;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	pointer = &dest[0];
	return (pointer);
}

int main (void)
{
	char *a = "Olameubem";
	char *b;
	
	ft_strcpy(*b, *a);
	for (int i = 0; i < 5; i++)
		printf("%c", b[i]);
}