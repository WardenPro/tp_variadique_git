/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_variadique_git/
 * created on:  Wed May 17 19:49:54 2023
 * 1st author:  user
 * description: vputs.c
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

int stu_vputs(unsigned int nbr, ...)
{
    int i;
    int j;
    char *value;
    va_list list;

    i = 1;
    j = 0;
    va_start(list, nbr);
    while (i <= nbr)
    {
        value = va_arg(list, char *);
        j = j + stu_puts(value);
        i += 1;
    }
    va_end(list);
    return j;
}