/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_variadique_git/
 * created on:  Wed May 17 19:49:54 2023
 * 1st author:  user
 * description: mini_printf.c
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>


int get_digit(int nb,int index)
{
    int power = index;
     if (nb < 0)
         {
             nb = nb * -1;
         } 
    if(index == 0)
        {
            return (nb % 10);
        }

    while(power > 1)
        {
            nb = nb / 10;
            power = power -1;
        }
    nb = nb %10;
    return (nb);
}
int stu_putchar(const char *c, int value)
{
    return (write(1, &*c, value));
}
int stu_puts(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i = i + 1;
    }
    if (stu_putchar(str, i) == -1)
    {
        return (-1);
    }
    return i;
}

int nb_len(int nb)
{
    int i = 0;
    if (nb < 0)
    {
        nb = nb * -1;
    }
    while (nb > 0)
    {
        nb = nb / 10;
        i = i + 1;
    }
    return i;
}

int stu_mini_printf(const char *pattern, ...)
{
    int i;
    int j;
    int mod;
    int tmp;
    const char *value;
    long int valued;
    va_list list;

    i = 0;
    j = 0;
    va_start(list, pattern);
    while (pattern[i] != '\0')
    {
        while(pattern[i] != '%' && pattern[i] != '\0')
        {
            stu_putchar(&pattern[i], 1);
            i++;
        }
        if (pattern[i] == '%' && pattern[i + 1] == 's')
        {
            value = va_arg(list, const char *);
            j = j + stu_puts(value);
            i += 1;
        }
        else if (pattern[i] == '%' && pattern[i + 1] == '%')
        {
            write(1, &"%", 1);
            j += 1;
        }
        else if (pattern[i] == '%' && pattern[i + 1] == 'd')
        {
            j = 0;
            valued = va_arg(list, long int);
            mod = nb_len(valued);
            if(valued <= 2147483647)
            {
                while (mod > j)
                {
                    tmp = get_digit(valued, mod) + '0';
                    write(1, &tmp, 1);
                    mod -= 1;
                }
            }
            i += 1;
        }
        i += 1;
    }
    va_end(list);
    return j;
}