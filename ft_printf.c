/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:08:52 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/05 17:48:29 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

static int	ft_print_var(va_list args, char c)
{
	if (c == 'c')
		ft_printf_putchar(va_arg(args, int));
	else if (c == 's')
		return (ft_printf_putstr(va_arg(args, char *)));
	/*else if (c == 'p')
		STUFF HERE
	else if (c == 'd')
		STUFF HERE
	else if (c == 'i')
		STUFF HERE
	else if (c == 'u')
		STUFF HERE*/
	else if (c == 'x')
		return (ft_printf_putnbr_hexa(va_arg(args, int), 0, 1));
	else if (c == 'X')
		return (ft_printf_putnbr_hexa(va_arg(args, int), 1, 1));
	else if (c == '%')
		ft_printf_putchar('%');
	else
		return (ft_printf_putstr("(null)"));
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		char_count;
	va_list	args;

	char_count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			char_count += ft_print_var(args, *str);
		}
		else
		{
			ft_printf_putchar(*str);
			char_count++;
		}
		str++;
	}
	va_end(args);
	return (char_count);
}
/*
int	main(void)
{
	int x = ft_printf("%s%ce su%%is %se rigolo\n%x | %X\n", "Coucou ", 'c', "toto l", 42, 42);
	int y = printf("%s%ce su%%is %se rigolo\n%x | %X\n", "Coucou ", 'c', "toto l", 42, 42);

	printf("-> %i | %i\n", x, y);
}*/
