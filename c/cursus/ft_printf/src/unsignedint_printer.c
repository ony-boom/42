/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignedint_printer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:34:37 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/05 21:04:21 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		printed += ft_putchar_fd(n + '0', 1);
	return (printed);
}

static int	printer(va_list params)
{
	unsigned int	n;

	n = va_arg(params, unsigned int);
	return (print_unsigned(n));
}
