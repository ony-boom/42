/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:20:21 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/21 23:32:22 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	hex_printer(unsigned int n, t_bool use_upper)
{
	int							printed;
	static const unsigned int	base = 16;

	printed = 0;
	if (n >= base)
	{
		printed += hex_printer((n / base), use_upper);
		printed += hex_printer((n % base), use_upper);
	}
	else
		printed += ft_putchar_fd((char)get_hex(n, use_upper), 1);
	return (printed);
}

int	hex_printer_fn(void *p_hex, t_bool use_upper)
{
	unsigned int	hex;

	hex = *(unsigned int *)p_hex;
	return (hex_printer(hex, use_upper));
}

int	lower_hex_printer_fn(void *p_hex)
{
	return (hex_printer_fn(p_hex, FALSE));
}

int	upper_hex_printer_fn(void *p_hex)
{
	return (hex_printer_fn(p_hex, TRUE));
}

int	print_hex(unsigned int hex, t_bool use_upper, t_format_config config)
{
	int							pad;
	int							printed;
	char						padding_char;
	int							(*print_fn)(void *);
	t_format_modifier_config	modifier;

	printed = 0;
	padding_char = ' ';
	print_fn = lower_hex_printer_fn;
	modifier = config.modifier_config;
	pad = modifier.pad.len - get_hex_len(hex);
	if (use_upper)
		print_fn = upper_hex_printer_fn;
	if (!config.has_config || (pad <= 0 && !config.modifier_config.pad.is_dot
			&& !config.modifier_config.prepend_hex_prefix))
		return (hex_printer(hex, use_upper));
	if (config.modifier_config.pad.is_zero || config.modifier_config.pad.is_dot)
		padding_char = '0';
	if (config.modifier_config.prepend_hex_prefix)
		printed += print_hex_prefix(hex, use_upper);
	printed += print_pad(get_print_pad_params(&hex, pad, padding_char,
				modifier.pad.is_right), print_fn);
	return (printed);
}
