/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:04:34 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/13 19:31:27 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int wordbegin;

	i = 0;
	wordbegin = 1;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && wordbegin == 1)
		{
			str[i] = str[i] - 32;
			wordbegin = 0;
		}
		if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
		{
			wordbegin = 1;
		};
		i++;
	}

	return(str);
}
