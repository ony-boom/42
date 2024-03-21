/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:21:44 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/21 12:23:39 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_number(long long digit, int (*print_fn)(long long *),
		t_format_config config)
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
		return (print_fn(&digit));
	if (config.modifier_config.pad.is_zero || config.modifier_config.pad.is_dot)
		padding_char = '0';
	printed += print_pad(get_print_pad_params(&digit, pad, padding_char,
				modifier.pad.is_right), (int (*)(void *))print_fn);
	return (printed);
}

int	digit_print_fn(void *p_digit)
{
	int	digit;

	digit = *(int *)p_digit;
	return (ft_putnbr_fd(digit, 1));
}

int	print_digit(int digit, t_format_config config)
{
    int printed;
    int absolute_digit;

    printed = 0;
    absolute_digit = (int)ft_abs(digit);
    if (digit < 0)
    {
        config.modifier_config.pad.len--;
        if (absolute_digit > 0)
            printed += ft_putchar_fd('-', 1);
    }
    printed += (print_number(absolute_digit, (int (*)(long long *))digit_print_fn, config));
    return printed;
}
