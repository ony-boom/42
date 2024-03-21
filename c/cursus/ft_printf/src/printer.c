/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:22:14 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/21 23:35:37 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	print_type(t_format_config config, va_list params)
{
	if (config.specifier == PERCENT)
		return (print_char('%', config));
	else if (config.specifier == CHAR)
		return (print_char(va_arg(params, int), config));
	else if (config.specifier == INTEGER || config.specifier == DECIMAL)
		return (print_digit(va_arg(params, int), config));
	else if (config.specifier == UNSIGNED_INT)
		return (print_unsigned(va_arg(params, unsigned int), config));
	else if (config.specifier == HEX || config.specifier == UPPER_HEX)
		return (print_hex(va_arg(params, unsigned long int),
				config.specifier == UPPER_HEX, config));
	// else if (config.specifier == POINTER)
	// 	return (print_ptr(va_arg(params, void *), config));
	else
		return (print_str(va_arg(params, char *), config));
}
