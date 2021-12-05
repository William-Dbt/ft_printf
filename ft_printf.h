/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:13:07 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/05 17:33:05 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define HEXA "0123456789ABCDEF"

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printf_strlen(char *str);
int		ft_printf_putstr(char *str);
int		ft_printf_putnbr_hexa(int nb, int caps, int count);

void	ft_printf_putchar(char c);

#endif
