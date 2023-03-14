/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:11:31 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/03/14 11:27:54 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void swap(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

char* convert_to_hex (char dec_c)
{
    char hex_c[2];
    int remainder;
    int i;
    char temp;

    i = 0;
    while (dec_c != 0)
    {
        remainder = dec_c%16;
        printf("dec_c = %i, remainder = %i\n", dec_c, remainder);
        if (remainder < 10)
        {
            hex_c[i] = remainder + 48;
            hex_c[i+1] = '0';
            printf("%i, %i", hex_c[0], hex_c[1]);
        }  
        else
        {
            hex_c[i] = remainder + 55;
            i++;
            printf("Step %i: dec_c = %i, remainder = %i, hex[%i] = ")
        }
        dec_c = dec_c / 16;
    }
    swap(&hex_c[0], &hex_c[1]);
    return(hex_c);    
}

void ft_putstr_non_printable (char * str)
{
    int i;
    char* unprintable_char[2];

    i = 0;
    while (str[i])
    {
        if ((str[i] > 31) && str[i] < 127)
            write(1, &str[i], 1);
        else
        {
            write(1, "\\", 2);
            printf("\n");
            unprintable_char[2] = convert_to_hex(str[i]);
            if (str[i] < 16)
            {
                write(1, unprintable_char[0], 1);
            }
            else
            {
                write(1, unprintable_char, 2);
            }
        }    
        i++;
    }
}

int main (void)
{
    char a[] = "Ola\nesta bem?";
    char b[] = "\n";
    ft_putstr_non_printable(b);
}