/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:15:49 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/07 09:21:42 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const t_format_specifier	*get_specifier_list(void)
{
	const static t_format_specifier	specifier_list[SPECIFER_LIST_SIZE] = {CHAR,
			INTEGER, STR, DECIMAL, POINTER, UNSIGNED_INT, HEX, UPPER_HEX,
			PERCENT};

	return (specifier_list);
}

// TODO: a lot of to do down there 👇️👇️
int	print_formatted(char *str, int *format_len, va_list params)
{
	int			printed;
	t_format	format;
	char		*formatted_str;

	printed = 0;
	format = get_format(str, format_len);
	return (0);
}

int	ft_printf(const char *base_str, ...)
{
	int		printed;
	va_list	params;
	int		format_len;
	int		is_after_format_sign;

	printed = 0;
	va_start(params, base_str);
	is_after_format_sign = 0;
	while (*base_str)
	{
		if (*base_str == '%' && !is_after_format_sign)
		{
			is_after_format_sign = 1;
			printed += print_formatted((char *)base_str++, &format_len, params);
			base_str += format_len;
			continue ;
		}
		printed += ft_putchar_fd(*base_str, 1);
		is_after_format_sign = 0;
		base_str++;
	}
	va_end(params);
	return (printed);
}
