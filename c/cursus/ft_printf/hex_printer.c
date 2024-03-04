/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:38:05 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/03 15:03:23 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	print_hex(unsigned long n, char *base, int *printed)
{
	if ((int)n >= ft_strlen(base))
		print_hex(n / ft_strlen(base), base, printed);
	*printed = ft_putchar_fd(base[n % ft_strlen(base)], 1);
}

int	hex_base_printf(va_list params, int uppper)
{
	long		n;
	int			printed;
	char		*base16;
	const char	base16_upper[] = "012345678ABCDEF";

	base16 = BASE_16;
	if (uppper)
		base16 = (char *)base16_upper;
	printed = 0;
	n = va_arg(params, int);
	if (n < 0)
	{
		n = ft_abs(n);
		printed += ft_putchar_fd('-', 1);
	}
	print_hex(n, base16, &printed);
	return (printed);
}

static int	print_lower_hex(va_list params)
{
	return (hex_base_printf(params, 0));
}

t_printer	*hex_lower_printer(void)
{
	return (printer_new(HEX, print_lower_hex));
}
