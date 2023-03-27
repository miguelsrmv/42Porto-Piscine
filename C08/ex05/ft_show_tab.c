void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_show_tab(struct s_stock_str *par)
{
    int size;

    size = 0;
    while (par[size].str)
        size++;
    

}