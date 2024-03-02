/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:15:49 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/02 12:16:15 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

void	print_based_on_type(t_format format, va_list params)
{
	const t_printer	**printers = get_printers();
	const t_printer	*printer = get_printer_at_format(printers, format);

	if (!printer || !printer->fn)
		return (ft_putchar_fd(va_arg(params, int), 1));
	printer->fn(params);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		printed_char;
	char	format_specifier;

	printed_char = 0;
	format_specifier = '%';
	va_start(params, str);
	while (*str)
	{
		if (*str == format_specifier)
		{
			print_based_on_type(*(++str), params);
			str++;
			continue ;
		}
		printed_char++;
		ft_putchar_fd(*str++, 1);
	}
	va_end(params);
	return (printed_char);
}

int	main(void)
{
	char	c;

	int		age;

	c = 'o';
	age = 21;
	ft_printf("%cny is my name, and i'm %i years old", c, age);
}
