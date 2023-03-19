/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:02:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/19 19:13:41 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_array(int array[10][10])
{
	int	a;
	int	b;

	a = 0;
	b = 0;
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
}

int	ft_ten_queens_puzzle(void)
{
	int	array[10][10];






	print_array(array);
}

int main (void)
{
	ft_ten_queens_puzzle();
}