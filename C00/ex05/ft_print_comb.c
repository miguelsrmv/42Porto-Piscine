/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:37:41 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/09 12:33:00 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
void ft_print_comb(void);

int main (void)
{
    ft_print_comb();
    return(0);
}
*/
void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = 48;
	while (a < 56)
	{
		b = a + 1;
		while (b < 57)
		{
			c = b + 1;
			while (c < 58)
			{
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);
				if ((a == 55) && (b == 56) && (c == 57))
					return ;
				write(1, ", ", 2);
				c = c + 1;
			}
			b = b + 1;
		}
		a = a + 1;
	}
}
