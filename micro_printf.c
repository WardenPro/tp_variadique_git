/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_variadique_git/
 * created on:  Wed May 17 19:49:54 2023
 * 1st author:  user
 * description: micro_printf.c
*/

#include <stdarg.h>
#include <unistd.h>

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
    if (stu_putchar(str, i) == -1) {
        return (-1);
    } 
    return i;
}

int stu_mini_printf(const char *pattern, ...)
{
    int i;
    int j;
    const char *value;
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
        if (pattern[i] == '%')
        {
            if (pattern[i + 1] == 's')
            {
                value = va_arg(list, const char *);
                j = j + stu_puts(value);
                i += 1;
            }
        }
        if (pattern[i] == '%')
        {
            if (pattern[i + 1] == '%')
            {
                write(1, &"%", 1);
                j += 1;
            }
        }

        i += 1;
    }
    va_end(list);
    return j;
}