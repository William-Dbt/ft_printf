/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:08:59 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/05 17:52:22 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_printf_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return (ft_printf_putstr("(null)"));
	i = 0;
	while (str[i])
	{
		ft_printf_putchar(str[i]);
		i++;
	}
	return (i);
}
