/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:15:49 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/16 17:01:13 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const t_format_specifier	*get_specifier_list(void)
{
	static const t_format_specifier	specifier_list[SPECIFER_LIST_SIZE] = {CHAR,
			INTEGER, STR, DECIMAL, POINTER, UNSIGNED_INT, HEX, UPPER_HEX,
			PERCENT, 0};

	return (specifier_list);
}

int	print_formatted(char *str, int *format_len, va_list params)
{
	int i;
	int len;
	t_format	format;
	int			printed_char;
	t_builded_str		formatted_str;

	printed_char = 0;
	format = get_format(str, format_len);
	formatted_str = new_str_builder(format, params);
	len = formatted_str.params_len + format.modifier.pad.len;
	if (formatted_str.params_len == format.modifier.pad.len)
		len -= formatted_str.params_len;
	i = 0;
	while (i < len)
			printed_char += ft_putchar_fd(formatted_str.str[i++], 1);
	free(formatted_str.str);
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
