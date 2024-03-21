/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:51:37 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/20 18:46:28 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	unsigned_printer(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
	{
		printed += unsigned_printer((n / 10));
		printed += unsigned_printer((n % 10));
	}
	else
		printed += ft_putchar_fd(n + '0', 1);
	return (printed);
}

int	unsigned_print_fn(void *p_unsigned)
{
	unsigned int	n;

	n = *(int *)p_unsigned;
	return (unsigned_printer(n));
}

int	print_unsigned(unsigned int digit, t_format_config config)
{
	return (print_number(digit, (int (*)(long long *))unsigned_print_fn,
		config));
}
