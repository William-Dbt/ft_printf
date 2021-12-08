#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	x = 0,
		y = 0,
		ptr_x = 2,
		ptr_y = 5;

	x = ft_printf("%c%c%c%c%c%c\n", 'c', 'o', 'u', 'c', 'o', 'u');
	y = printf("%c%c%c%c%c%c\n", 'c', 'o', 'u', 'c', 'o', 'u');
	printf("ft : %i, lib : %i\n", x, y);
	x = ft_printf("%s %s %s %s\n", "Coucou je", "suis", "toto le", "rigolo\n");
	y = printf("%s %s %s %s\n", "Coucou je", "suis", "toto le", "rigolo\n");
	printf("ft : %i, lib : %i\n", x, y);
	x = ft_printf("ptr x : %p | ptr y : %p | ptr null : %p\n", &ptr_x, &ptr_y, NULL);
	y = printf("ptr x : %p | ptr y : %p | ptr null : %p\n", &ptr_x, &ptr_y, NULL);
	printf("ft : %i, lib : %i\n", x, y);
	x = ft_printf("%d | %d | %d | %d | %d\n", 2147483647, -2147483648, 0, NULL);
	y = printf("%d | %d | %d | %d | %d\n", 2147483647, -2147483648, 0, NULL);
	printf("ft : %i, lib : %i\n", x, y);
	x = ft_printf("%i | %i | %i | %i | %i\n", 2147483647, -2147483648, 0, NULL);
	y = printf("%i | %i | %i | %i | %i\n", 2147483647, -2147483648, 0, NULL);
	printf("ft : %i, lib : %i\n", x, y);
	x = ft_printf("%u | %u | %u | %u\n", 3147483648, -42, 0, NULL);
	y = printf("%u | %u | %u | %u\n", 3147483648, -42, 0, NULL);
	printf("ft : %i, lib : %i\n", x, y);
	x = ft_printf("%x | %x | %x | %x\n", -1, 42, 2147483647, 0);
	y = printf("%x | %x | %x | %x\n", -1, 42, 2147483647, 0);
	printf("ft : %i, lib : %i\n", x, y);
	x = ft_printf("Cou%%%%%% j%% sui%% %%%%%%%% le rig%%ol%%\n", 42);
	y = printf("Cou%%%%%% j%% sui%% %%%%%%%% le rig%%ol%%\n", 42);
	printf("ft : %i, lib : %i\n", x, y);
	return (0);
}
