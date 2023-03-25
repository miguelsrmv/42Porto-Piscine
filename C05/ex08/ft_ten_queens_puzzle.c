/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:02:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/25 19:45:52 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//Array[collumn] = linha que ocupa em dada coluna

int position_valid (int collumn, int *array)
{
	int pos_check;

	pos_check = 0;
	while (pos_check < collumn)															// Posicoes horizontais
	{
		if (array[collumn] == array[pos_check])
			return (0);
		pos_check++;
	}
	pos_check = 1;
	while (pos_check <= collumn && collumn - pos_check >= 0)							// Posicoes diagonais para cima
	{
		if (array[collumn - pos_check] == array[collumn] - pos_check)
			return (0);
		pos_check++;
	}
	pos_check = 1;
	while (pos_check <= collumn && collumn + pos_check < 10)							// Posicoes diagonais para baixo
	{
		if (array[collumn - pos_check] == array[collumn] + pos_check)
			return (0);
		pos_check++;
	}
	return (1);
}

void success (int *array, int *counter)
{
	int i;

	i = 0;
	while (array[i])
	{
		write(1, &array[i], 1);
		write(1, "\n", 1);
		i++;
	}
	(*counter)++;
	return ;
}

int	put_queen(int collumn, int *array, int *counter)
{
	// Caso base >> Ultima solucao... desnecessario ???
	if (array[0] == 10)
		return (0);
	// Caso recursivo
	while (array[collumn] < 10)
	{
		while (position_valid(collumn, array) == 0)
		{
			if (array[collumn] == 9) // Se na ultima linha
				return (0);
			else // Verifica que 
				array[collumn]++;
		}
		if (collumn == 10)
		{
			success(array, counter);
			return (1);
		}
		else
		{
			put_queen(collumn + 1, array, counter);
			array[collumn]++; // ?????
		}
	}
}


int	ft_ten_queens_puzzle(void)
{
	// 
	int array[10];
	int counter;

	counter = 0;
	array[0] = 0;
	put_queen(0, array, &counter);
	return (counter);
}

int main (void)
{
	ft_ten_queens_puzzle();
}