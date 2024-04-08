/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:36:36 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/08 07:08:45 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_type(t_format_config *config, va_list params)
{
	if (config->specifier == CHAR)
		return (print_char(va_arg(params, int), config));
	if (config->specifier == PERCENT)
		return (print_char('%', config));
	if (config->specifier == DECIMAL || config->specifier == INTEGER)
	  return (print_number((va_arg(params, int)), config));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int				printed;
	va_list			params;
	t_format_config	format_config;

	va_start(params, format);
	printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format_config = new_format_config((char *)format);
			printed += print_type(&format_config, params);
			format += format_config.len;
			free(format_config.modifiers);
			continue ;
		}
		printed += ft_putchar_fd(*format++, 1);
	}
	va_end(params);
	return (printed);
}
