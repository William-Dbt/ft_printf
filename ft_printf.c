/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:08:52 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/04 17:17:48 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

static void	ft_print_var(va_list args, char c)
{
	(void)args;
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	/*else if (c == 's')
		STUFF HERE
	else if (c == 'p')
		STUFF HERE
	else if (c == 'd')
		STUFF HERE
	else if (c == 'i')
		STUFF HERE
	else if (c == 'u')
		STUFF HERE
	else if (c == 'x')
		STUFF HERE
	else if (c == 'X')
		STUFF HERE*/
	else if (c == '%')
		ft_putchar('%');
	else
	{
		ft_putchar('%');
		ft_putchar(c);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			ft_print_var(args, *str);
		}
		else
			ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("Coucou %ce suis %coto %c%c rigo%%lo", 'j', 't', 'l', 'e');
}
