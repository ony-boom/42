/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:36:36 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/19 08:16:06 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int				printed;
	va_list			params;
	t_format_config	format_config;

	va_start(params, str);
	printed = 0;
	while (*str)
	{
		if (*str == '%')
		{
			format_config = get_format_config(++str);
			printed += print_type(format_config, params);
			str += format_config.format_len;
			continue ;
		}
		printed += ft_putchar_fd(*str++, 1);
	}
	va_end(params);
	return (printed);
}
