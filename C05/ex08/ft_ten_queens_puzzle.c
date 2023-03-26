/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:02:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/26 02:26:54 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	position_valid(int collumn, int *array)
{
	int	pos_check;

	pos_check = 0;
	while (pos_check < collumn)
	{
		if (array[collumn] == array[pos_check])
			return (0);
		pos_check++;
	}
	pos_check = 1;
	while (pos_check <= collumn && array[collumn] - pos_check >= 0)
	{
		if (array[collumn - pos_check] == array[collumn] - pos_check)
			return (0);
		pos_check++;
	}
	pos_check = 1;
	while (pos_check <= collumn && array[collumn] + pos_check < 10)
	{
		if (array[collumn - pos_check] == array[collumn] + pos_check)
			return (0);
		pos_check++;
	}
	return (1);
}

void	success(int *array, int *counter)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = array[i] + '0';
		write (1, &c, 1);
		i++;
	}
	write (1, "\n", 1);
	(*counter)++;
	return ;
}

int	end_of_collumn(int collumn, int *array)
{
	if (array[collumn] == 9)
	{
		array[collumn] = 0;
		return (0);
	}
	return (1);
}

int	put_queen(int collumn, int *array, int *counter)
{
	while (array[collumn] < 10)
	{
		while (position_valid(collumn, array) == 0)
		{
			if (end_of_collumn(collumn, array) == 0)
				return (0);
			array[collumn]++;
		}
		if (collumn == 9)
		{
			success(array, counter);
			if (end_of_collumn(collumn, array) == 0)
				return (0);
			array[collumn]++;
			return (0);
		}
		else
		{
			put_queen(collumn + 1, array, counter);
			if (end_of_collumn(collumn, array) == 0)
				return (0);
			array[collumn]++;
		}
	}
	return (1);
}

int	ft_ten_queens_puzzle(void)
{
	int	array[10];
	int	i;
	int	counter;

	i = 0;
	while (i < 10)
	{
		array[i] = 0;
		i++;
	}
	counter = 0;
	put_queen(0, array, &counter);
	return (counter);
}

/*
int main (void)
{
	ft_ten_queens_puzzle();
}
*///