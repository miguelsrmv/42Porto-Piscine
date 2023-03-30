#include <stdlib.h>

int str_len(char *str)
{
    int i;
    i = 0;

    while(str[i])
        i++;
    
    return(i);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int totalsize;
    int i;
    int j;
    int k;
    char *joinstring;

    totalsize = str_len(sep) * (size - 1);
    i = 0;

    if (size == 0)
        return (" ");

    while (i < size)
    {
        totalsize += str_len(strs[i]);
        i++;
    }

    joinstring = malloc(totalsize + 1);

    i = 0;
    j = 0;
    k = 0;
    while (strs[i] && k < totalsize)
    {
        j = 0;
        while (strs[i][j])
        {
            joinstring[k] = strs[i][j];
            k++;
            j++;
        }
        j = 0;
        while (sep[j] && i < size - 1)
        {
            joinstring[k] = sep[j];
            k++;
            j++;
        }
        i++;
    }
    joinstring[k] = '\0';
    return(joinstring);
}


#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int		main(void)
{
	int		offset;
	char	**strs;
	char	*res_str;

	strs = malloc(3 * sizeof(char *));
	if (strs == NULL)
		return (1);
	offset = 0;
	while (offset < 3)
	{
		strs[offset] = "abc";
		offset++;
	}
	res_str = ft_strjoin(3, strs, ", ");
	if (res_str == NULL)
		return (1);
	printf("res: %s\n", res_str);
	free(strs);
	free(res_str);
	return (0);
}
