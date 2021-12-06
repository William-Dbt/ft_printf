/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:19:15 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/06 11:10:33 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putnbr(int nb, int count)
{
	long int	nbr;

	nbr = nb;
	if (nb < 0)
	{
		count++;
		ft_printf_putchar('-');
		nbr = -nbr;
	}
	if (nbr <= 9)
		ft_printf_putchar(nbr + '0');
	else
	{
		count = ft_printf_putnbr(nbr / 10, count);
		ft_printf_putchar((nbr % 10) + '0');
	}
	return (++count);
}

int	ft_printf_putnbr_u(unsigned int nb, int count)
{
	if (nb <= 9)
		ft_printf_putchar(nb + '0');
	else
	{
		count = ft_printf_putnbr(nb / 10, count);
		ft_printf_putchar((nb % 10) + '0');
	}
	return (++count);
}
