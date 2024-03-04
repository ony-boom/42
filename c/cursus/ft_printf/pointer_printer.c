/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:49:48 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/04 06:57:34 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	return ('a' + v - 10);
}

static int	print_ptr(void *p0)
{
	int			shift;
	int			printed;
	uintptr_t	p;

	printed = 0;
	p = (uintptr_t)p0;
	printed += ft_putstr_fd("0x", 1);
	shift = (sizeof(p) << 3) - 4;
	while (shift >= 0 && ((p >> shift) & 0xf) == 0)
		shift -= 4;
	while (shift >= 0)
	{
		printed += ft_putchar_fd(hex_digit((p >> shift) & 0xf), 1);
		shift -= 4;
	}
	return (printed);
}

int	printer(va_list params)
{
	return (print_ptr(va_arg(params, void *)));
}

t_printer	*pointer_printer(void)
{
	return (printer_new(POINTER, printer));
}
