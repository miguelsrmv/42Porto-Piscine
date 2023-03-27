#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*n;

	i = 0;
	while (src[i])
		i++;
	n = malloc(i * sizeof(char) + 1);
	if (!n)
		return (NULL);
	ft_strcpy(n, src);
	return (n);
}

struct  s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    int i;
    t_stock_str *s_stock_str;

    s_stock_str = malloc(ac * sizeof(t_stock_str) + 1);
    if (!s_stock_str)
        return (NULL);
    i = 0;
    while (i < ac)
    {
        s_stock_str[i].size = ft_strlen(av[i]);
        s_stock_str[i].str = av[i];
        s_stock_str[i].copy = ft_strdup(av[i]);
        i++;
    }
    s_stock_str[i].str = 0;
    return (s_stock_str);
}
