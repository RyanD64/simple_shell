#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
  * main - core of shell
  * Return: 1 otherwise Fail
  */


int main(void)
{
char	*buffer = NULL;
size_t	buf_size = 2048;

buffer = (char *)calloc(sizeof(char), buf_size);
if (buffer == NULL)
{
	perror("Malloc failure");
	return (EXIT_FAILURE);
}

write(1, "$> ", 3);

while (getline(&buffer, &buf_size, stdin) > 0)
{
printf("cmd = %s\n", buffer);
write(1, "$> ", 3);
}

printf("Bye \n");
free(buffer);
}
