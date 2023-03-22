/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:37:38 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/22 10:21:44 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_print_params(int size, char *parameters[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (parameters[i][j])
		{
			write(1, &parameters[i][j], 1);
			j++;
		}
		j = 0;
		i++;
		write(1, "\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	int		iterate;
	int		size;
	char	*temp;

	iterate = 1;
	size = argc;
	while (size > 1)
	{
		while (iterate < size - 1)
		{
			if (ft_strcmp(argv[iterate], argv[iterate + 1]) > 0)
			{
				temp = argv[iterate];
				argv[iterate] = argv[iterate + 1];
				argv[iterate + 1] = temp;
			}
			iterate++;
		}
		iterate = 1;
		size--;
	}
	ft_print_params(argc - 1, &argv[1]);
}
