/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:28:15 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/15 14:23:05 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	starting_index;
	int	ending_index;
	int	number;

	number = 0;
	starting_index = 0;
	while (str[starting_index] < 48 || str[starting_index] > 57)
		starting_index++;
	ending_index = starting_index;
	while (str[ending_index] > 47 && str[ending_index] < 58)
		ending_index++;
	while (starting_index < ending_index)
	{
		number *= 10;
		number += (int)(str[starting_index] - '0');
		starting_index++;
	}
	while (starting_index > 0)
	{
		if (str[starting_index] == 45)
			number = -number;
		starting_index--;
	}
	return (number);
}
