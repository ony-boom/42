/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:15:49 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/16 12:59:17 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

const t_format_specifier	*get_specifier_list(void)
{
	static const t_format_specifier	specifier_list[SPECIFER_LIST_SIZE] = {CHAR,
			INTEGER, STR, DECIMAL, POINTER, UNSIGNED_INT, HEX, UPPER_HEX,
			PERCENT, 0};

	return (specifier_list);
}

int	print_formatted(char *str, int *format_len, va_list params)
{
	t_format	format;
	int			printed_char;
	char		*formatted_str;

	printed_char = 0;
	format = get_format(str, format_len);
	formatted_str = new_str_builder(format, params);
	if (!*formatted_str && format.specifier == CHAR)
		printed_char += ft_putchar_fd(0, 1);
	else
		printed_char += ft_putstr_fd(formatted_str, 1);
	free(formatted_str);
	return (printed_char);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		printed_char;
	int		format_len;

	printed_char = 0;
	va_start(params, str);
	while (*str)
	{
		if (*str == '%')
		{
			printed_char += print_formatted((char *)(++str), &format_len,
					params);
			str += format_len;
			continue ;
		}
		printed_char++;
		ft_putchar_fd(*str++, 1);
	}
	va_end(params);
	return (printed_char);
}
