#include <stdio.h>
#include <stdlib.h>

int is_in_charset(char c, char *charset)
{
    int i;

    i = 0;
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
    int wordbegin;
    wordbegin = 1;

    while (str[i])
    {
        if (is_in_charset(str[i], charset) == 1)                          // Se caracter esta em charset
            wordbegin = 1;
        else if (is_in_charset(str[i], charset) == 0 && wordbegin == 1)   // Se nao esta E a palavra comeca
        {
            wordbegin = 0;
            words++;  
        }
        i++;
    }
    return (words);
}

char *substring(char *str, char *charset, int *n)
{
    int sublen;
    sublen = 0;
    int i;

    while(str[sublen] && is_in_charset(str[sublen], charset) == 0)
        sublen++;
    
    char* substring;

    substring = malloc(sublen + 1);

    i = 0;
    while (i < sublen)
    {
        substring[i] = str[i];
        i++;
    }
    substring[i] = '\0';
    while(str[i] && is_in_charset(str[i], charset) == 1)
        i++;
    *n = (*n) + i;

    return(substring);
}

char **ft_split(char *str, char *charset)
{
    int words;
    words = count_words(str, charset);
    char **array;
    array = malloc(words * sizeof(char *) + 1);

    int i;
    i = 0;
    int j;
    j = 0;
    while(str[j] && is_in_charset(str[j], charset) == 1)
        j++;
    while (i < words)
    {
        array[i] = substring(&str[j], charset, &j);
        i++;
    }
    array[i] = 0;
    return(array);
}


int		main(void)
{
	int		str_n;
	char	*str;
	char	*sep;
	char	**strs;

	str = "yyWfrONjnyyoiSQ5GYKxJ6NSlqrUtPkklcoKR fyy";  // WfrONjn    oi      Q5GYKxJ6N       lqrUtPkklcoKR f"
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
