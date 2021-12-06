/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_hexa.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:22:49 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/06 12:30:24 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putnbr_hexa(int nb, int caps, int count)
{
	unsigned int	nbr;

	nbr = nb;
	if (nbr <= 15)
	{
		if (caps && (nbr >= 10 && nbr <= 15))
			ft_printf_putchar(HEXA[nbr] - 32);
		else
			ft_printf_putchar(HEXA[nbr]);
	}
	else
	{
		count = ft_printf_putnbr_hexa(nbr / 16, caps, count);
		nbr %= 16;
		if (caps && (nbr >= 10 && nbr <= 15))
			ft_printf_putchar(HEXA[nbr] - 32);
		else
			ft_printf_putchar(HEXA[nbr]);
	}
	return (++count);
}

int	ft_printf_putnbr_hexa_u(unsigned long long int nb, int count)
{
	if (nb <= 15)
		ft_printf_putchar(HEXA[nb]);
	else
	{
		count = ft_printf_putnbr_hexa_u(nb / 16, count);
		ft_printf_putchar(HEXA[nb % 16]);
	}
	return (++count);
}
