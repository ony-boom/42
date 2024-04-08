/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:08:29 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/08 14:27:58 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					init_number_format(t_number_format *format);

void					set_pad(t_pad *pad, t_format_config_modifier *modifier,
							int to_print_len, t_bool is_negative);

void					set_max_width(t_number_format *format,
							t_format_config_modifier *modifier,
							int to_print_len);

void					set_sign(t_number_format *format,
							t_format_config_modifier *modifier,
							int to_print_len, t_bool is_negative);

static t_number_format	build_format(t_format_config *config, int to_print_len,
		t_bool is_negative)
{
	int							i;
	t_number_format				format;
	t_format_config_modifier	current_modifier;

	init_number_format(&format);
	i = 0;
	while (i < config->modifiers_size)
	{
		current_modifier = config->modifiers[i];
		if (current_modifier.modifier_specifier == DIGIT
			|| current_modifier.modifier_specifier == ZERO
			|| current_modifier.modifier_specifier == MINUS)
			set_pad(&format.space_pad, &current_modifier, to_print_len,
				is_negative);
		if (current_modifier.modifier_specifier == DOT)
			set_max_width(&format, &current_modifier, to_print_len);
		if (current_modifier.modifier_specifier == PLUS
			|| current_modifier.modifier_specifier == SPACE)
			set_sign(&format, &current_modifier, to_print_len, is_negative);
		i++;
	}
	return (format);
}

int	print_max_width(int n, t_pad *pad, t_bool show_sign)
{
	int		abs_n;
	int		printed;
	t_bool	is_negative;

	printed = 0;
	abs_n = ft_abs(n);
	is_negative = n < 0;
	if (is_negative && show_sign)
		printed += ft_putchar_fd('-', 1);
	printed += print_repeat(pad->padding_char, pad->count);
	if (abs_n == MY_INT_MIN)
	{
		printed += ft_putnbr_fd(2, 1);
		abs_n = 147483648;
	}
	printed += ft_putnbr_fd(abs_n, 1);
	return (printed);
}

int	print_number_with_format(int n, t_number_format *format)
{
	int		printed;
	t_bool	show_negative_sign;

	printed = 0;
	show_negative_sign = (t_bool)(format->space_pad.padding_char != ZERO
			|| n > 0);
	if (!show_negative_sign)
		printed += ft_putchar_fd('-', 1);
	if (format->space_pad.from_right)
	{
		if (format->sign.show)
			printed += ft_putchar_fd(format->sign.positive_sign, 1);
		printed += print_max_width(n, &(format->zero_pad), show_negative_sign);
		printed += print_repeat(format->space_pad.padding_char,
				format->space_pad.count);
	}
	else
	{
		printed += print_repeat(format->space_pad.padding_char,
				format->space_pad.count);
		if (format->sign.show)
			printed += ft_putchar_fd(format->sign.positive_sign, 1);
		printed += print_max_width(n, &(format->zero_pad), show_negative_sign);
	}
	return (printed);
}

int	print_number(int n, t_format_config *config)
{
	int				n_len;
	int				printed;
	t_number_format	format;

	printed = 0;
	n_len = get_int_len(ft_abs(n));
	format = build_format(config, n_len, (t_bool)(n < 0));
	printed += print_number_with_format(n, &format);
	return (printed);
}
