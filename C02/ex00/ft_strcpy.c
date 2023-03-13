/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:11:52 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/13 11:14:04 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strcpy   (char *dest, char *src)
{
    int i;

    i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    
    dest[i] = '\0';
}
