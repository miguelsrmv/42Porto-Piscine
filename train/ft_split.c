#include <stdio.h>
#include <stdlib.h>

int is_in_charset(char c, char *charset)
{
    int i;

    while (charset[i])
    {
        if (charset[i] == c)
            return(1);
        i++;
    }
    return(0);
}

int count_words(char *str, char *charset)
{
    int words;
    words = 0;
    int i;
    i = 0;

    while (str[i])
    {
        if (is_in_charset(str[i]) == 1)
            i++;
        else
        {
            words++;
            while (is_in_charset(str[i]) == 0)
                i++;
        }
    }
    return (words);
}


char **ft_split(char *str, char *charset)
{
    int words;
    words = count_words(str, charset);


}


int		main(void)
{
	int		str_n;
	char	*str;
	char	*sep;
	char	**strs;

	str = "WfrONjnyoiSQ5GYKxJ6NSlqrUtPkklcoKR f";
	sep = "ySzX";
	strs = ft_split(str, sep);
	str_n = 0;
	while (strs[str_n] != 0)
	{
		printf("[%d]: %s\n", str_n, strs[str_n]);
		str_n++;
	}
	free(strs);
	return (0);
}
