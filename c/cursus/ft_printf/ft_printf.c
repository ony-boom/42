/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:15:49 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/04 06:59:11 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	print_based_on_type(t_format format, va_list params, t_printer **printers)
{
	t_printer	*printer;

	printer = get_printer_at_format(printers, format);
	if (!printer || !printer->fn)
		return (ft_putchar_fd(va_arg(params, int), 1));
	return (printer->fn(params));
}

/* int	print_based_on_type(char *str, va_list params, t_printer **printers)
{
	t_printer	*printer;
	t_format format;

	format = *str;
	printer = get_printer_at_format(printers, format);
	if (!printer || !printer->fn)
		return (ft_putchar_fd(va_arg(params, int), 1));
	return (printer->fn(params, str++));
} */
int	ft_printf(const char *str, ...)
{
	va_list		params;
	int			printed_char;
	char		format_specifier;
	t_printer	**printers;

	printed_char = 0;
	format_specifier = '%';
	va_start(params, str);
	printers = init_printers();
	while (*str)
	{
		if (*str == format_specifier)
		{
			printed_char += print_based_on_type(*(++str), params, printers);
			str++;
			continue ;
		}
		printed_char++;
		ft_putchar_fd(*str++, 1);
	}
	va_end(params);
	free_mem(printers);
	return (printed_char);
}
