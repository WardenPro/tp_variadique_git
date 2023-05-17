/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_variadique_git/
 * created on:  Wed May 17 19:49:54 2023
 * 1st author:  user
 * description: micro_printf.test.c
*/

int stu_mini_printf(const char *pattern, ...);

void main(void)
{
    stu_mini_printf("%% %s %s %bonjour","et zizou", "et zidane");
}