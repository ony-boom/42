/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:22:14 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/18 07:40:04 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int	print_unsigned(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
	{
		printed += print_unsigned((n / 10));
		printed += print_unsigned((n % 10));
	}
	else
		printed += ft_putchar_fd((char)(n + '0'), 1);
	return (printed);
}

static int	print_hex(unsigned int n, int use_upper)
{
	int							printed;
	static const unsigned int	base = 16;

	printed = 0;
	if (n >= base)
	{
		printed += print_hex((n / base), use_upper);
		printed += print_hex((n % base), use_upper);
	}
	else
		printed += ft_putchar_fd((char)get_hex(n, use_upper), 1);
	return (printed);
}

static int	print_ptr(void *pointer_like)
{
	int			shift;
	int			printed;
	uintptr_t	ptr;

	printed = 0;
	ptr = (uintptr_t)pointer_like;
	if (!ptr)
	{
		printed += ft_putstr_fd("(nil)", 1);
		return (printed);
	}
	printed += ft_putstr_fd("0x", 1);
	shift = (sizeof(ptr) << 3) - 4;
	while (shift >= 0 && ((ptr >> shift) & 0xf) == 0)
		shift -= 4;
	while (shift >= 0)
	{
		printed += ft_putchar_fd((char)get_hex((ptr >> shift) & 0xf, 0), 1);
		shift -= 4;
	}
	return (printed);
}

static int	print_str(char *str)
{
	if (!str || !*str)
	{
		if (!str)
			return (ft_putstr_fd("(null)", 1));
		return (0);
	}
	return (ft_putstr_fd(str, 1));
}

int	print_type(t_format_config config, va_list params)
{
	// TODO: The work is here build a printer for each type
	// that handle passed configuration
	if (config.specifier == PERCENT)
		return (ft_putchar_fd('%', 1));
	else if (config.specifier == CHAR)
		return (ft_putchar_fd(va_arg(params, int), 1));
	else if (config.specifier == INTEGER || config.specifier == DECIMAL)
		return (ft_putnbr_fd(va_arg(params, int), 1));
	else if (config.specifier == UNSIGNED_INT)
		return (print_unsigned(va_arg(params, unsigned int)));
	else if (config.specifier == HEX || config.specifier == UPPER_HEX)
		return (print_hex(va_arg(params, unsigned int),
				config.specifier == UPPER_HEX));
	else if (config.specifier == POINTER)
		return (print_ptr(va_arg(params, void *)));
	else
		return (print_str(va_arg(params, char *)));
}
