/*
 * E89 Pedagogical & Technical Lab
 * project:     tp_variadique_git/
 * created on:  Wed May 17 19:49:54 2023
 * 1st author:  user
 * description: mini_printf.test.c
*/

int stu_mini_printf(const char *pattern, ...);

void main(void)
{
    stu_mini_printf("%% %d\n %s bonjour",123, "TEST");
}