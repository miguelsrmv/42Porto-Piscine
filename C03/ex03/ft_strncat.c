/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:22:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/15 12:26:42 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	dest_i;
	int	src_i;

	dest_i = 0;
	src_i = 0;
	while (dest[dest_i])
		dest_i++;
	while (src[src_i] && src_i < nb)
	{
		dest[dest_i] = src[src_i];
		dest_i++;
		src_i++;
	}
	dest[dest_i] = '\0';
	return (&dest[0]);
}
