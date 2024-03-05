/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:38:05 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/05 19:25:49 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_hex(int n, int use_upper)
{
	char	c;

	if (n < 10)
		return ('0' + n);
	else
	{
		c = 'a';
		if (use_upper)
			c = 'A';
		return (c + n - 10);
	}
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
		printed += ft_putchar_fd(get_hex(n, use_upper), 1);
	return (printed);
}

int	hex_base_printf(va_list params, int use_upper)
{
	unsigned int	n;

	n = va_arg(params, unsigned int);
	return (print_hex(n, use_upper));
}

static int	print_lower_hex(va_list params)
{
	return (hex_base_printf(params, 0));
}

t_printer	*hex_lower_printer(void)
{
	return (printer_new(HEX, print_lower_hex));
}
