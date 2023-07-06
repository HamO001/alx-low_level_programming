#include <stdio.h>

/**
 * main - print alabets in lowercase
 *
 * Return: Always 0 when success
 */
int main(void)

{
char alp[26] = "abcdefghijklmnopqrstuvwxyz";
int i;

for (i = 0; i < 26; i++)
{
putchar(alp[i]);
}
putchar('\n');
return (0);
}
