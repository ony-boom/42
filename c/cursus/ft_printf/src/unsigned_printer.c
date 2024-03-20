/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:51:37 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/20 17:53:49 by rony-lov         ###   ########.fr       */
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

int unsigned_print_fn(void *p_unsigned)
{
	unsigned int n;

	n = *(int *)p_unsigned;
	return unsigned_printer(n);
}

int	print_unsigned(unsigned int digit, t_format_config config)
{
	int							pad;
	int							printed;
	char						padding_char;
	t_format_modifier_config	modifier;

	printed = 0;
	padding_char = ' ';
	modifier = config.modifier_config;
	pad = modifier.pad.len - get_int_len(digit);
	if (!config.has_config || (pad <= 0 && !config.modifier_config.pad.is_dot))
		return (unsigned_printer(digit));
	if (config.modifier_config.pad.is_zero || config.modifier_config.pad.is_dot)
		padding_char = '0';
	printed += print_pad(
		(t_print_pad_params){
			.rest = &digit,
			.padding_count = pad,
			.padding_char = padding_char,
			.is_right = modifier.pad.is_right,
		},
		digit_print_fn);
	return (printed);
}
