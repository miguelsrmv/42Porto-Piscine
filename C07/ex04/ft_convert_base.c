/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:23:03 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/22 11:40:35 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int		i;
	int		j;
	int		base_length;

	base_length = 0;
	while (base[base_length])
		base_length++;
	if (base_length < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == '\f'
			|| base[i] == '\t' || base[i] == ' ' || base[i] == '\n'
			|| base[i] == '\r' || base[i] == '\v')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (base_length);
}

void	whitespace_and_sign(char *nbr, int *i, char *result, int *array_index)
{
	int		number_index;
	int		sign;

	number_index = 0;
	sign = 1;
	while (nbr[number_index] == '\f' || nbr[number_index] == '\t'
		|| nbr[number_index] == ' ' || nbr[number_index] == '\n'
		|| nbr[number_index] == '\r' || nbr[number_index] == '\v')
		j++;
	while (nbr[number_index] && (nbr[number_index] == '+'
			|| nbr[number_index] == '-'))
	{
		if (nbr[number_index] == '-')
			*sign = -(*sign);
		j++;
	}
	*i = number_index;
	if (sign == -1)
	{
		result[0] = '-';
		*array_index = 1;
	}
	else
		*array_index = 0;
}

int	is_char_in_base(char c, char *base)
{
	char		i;

	while (base[i] != c && base[i])
		i++;
	if (base[i] == c)
		return (1);
	return (0);
}

void	convert_from_to_base(char *c, char *base_from, char *base_to, int base_length)
{
	int		i;
	char	*number;
	int		decimal_value;

	decimal_value = 0;
	
	i = 0;
	while (base_from[i] =! c)
		i++;
	while (i > 0)
		if (i < base_length)
			
		else
		
		
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_index;
	int		array_index;
	char	*result;
	int		base_length;

	base_length = check_base(*base_from);
	if (base_length == 0)
		return (0);
	whitespace_and_sign(nbr, &nbr_index, result, &array_index);
	while (nbr[nbr_index] && is_char_in_base(nbr[nbr_index], base_from))
	{
		
		result *= base_length;
		result += convert_int_from_base(str[nbr_index], base);
		nbr_index++;
	}
	

	return (result);
}
