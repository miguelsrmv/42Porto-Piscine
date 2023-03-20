/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:02:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/19 20:34:44 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_array(int array[10][10])
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	printf("\n");
	printf("    0 1 2 3 4 5 6 7 8 9\n");
	printf("    _ _ _ _ _ _ _ _ _ _ \n");
	while (a < 10)
	{
		printf("%i | ", a);
		while (b < 10)
		{
			printf("%i ", array[a][b]);
			b++;
		}
		b = 0;
		printf("\n");
		a++;
	}
	printf("\n");
}

int	clash_check(int array[10][10], int x, int y)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (array[i][y] == 1)
			return (1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (array[x][y] == 1)
			return (1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (array[x + i][y + i] == 1 || array[x + i][y - i] == 1
			|| array[x - i][y + 1] == 1 || array[x - 1][y + 1] == 1)
			return (1);
		i++;
	}
	return (0);
}

void	populate_array(int x, int y, int array[10][10])
{
	while (x < 10)
	{
		while (y < 10)
		{
			if (clash_check(array, x, y) == 0)
				array[x][y] == 1;
			else
				y++;
		}
		x++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	array[10][10];

	populate_array(1, 1, array);
	print_array(array);
}

int main (void)
{
	ft_ten_queens_puzzle();
}