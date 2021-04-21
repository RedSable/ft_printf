#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
// #include "libft.h"
#include <unistd.h>

void	check(const char *fmt, ...)
{
	va_list		args;
	int			i;

	va_start(args, fmt);
	i = 0;
	while (i < 1)
	{
		int j = va_arg(args, int);
		// printf("%c\n", j + '\0');
		write(1, &j, 1);
		i++;
	}
	va_end(args);
}

int		main()
{
	// char	*op = "kek";
	// char	*po;
	unsigned long		one = 1;
	char	two = '2';

	// po = op;
	// check("kek", 'a');
	// printf("%c\n%d\n%d\n%d\n%d\n", 'q',1,1,1,1,1,1,1,1);
	printf("%d\n", sizeof(one));
	printf("%d\n", sizeof((void *)two));
	// printf("0x7ffe%x\n", &po);
	return (0);
}