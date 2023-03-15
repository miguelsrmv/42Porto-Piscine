/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:04:34 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/15 12:26:04 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int	is_alphanumeric(char *a)
{
	if (*a >= 'A' && *a <= 'Z')
		return (1);
	if (*a >= 'a' && *a <= 'z')
		return (1);
	if (*a >= '0' && *a <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	wordbegin;

	i = 0;
	wordbegin = 1;
	while (str[i])
	{
		ft_strlowcase(&str[i]);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' && wordbegin == 1)
			str[i] = str[i] - 32;
		if (is_alphanumeric(&str[i]) == 1)
			wordbegin = 0;
		else
			wordbegin = 1;
		i++;
	}
	return (str);
}
