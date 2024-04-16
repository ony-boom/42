/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:20:27 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/15 22:20:52 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						get_hex(int n, int use_upper);

void					init_number_format(t_number_format *format,
							long long n);

void					set_pad(t_pad *pad, t_format_config_modifier *modifier,
							int to_print_len, t_bool is_negative);

void					set_max_width(t_number_format *format,
							t_format_config_modifier *modifier,
							int to_print_len);

int						print_number_with_format(long long n,
							t_number_format *format, int (*printer)(long long,
								t_number_format *, t_bool));

int						print_hex_prefix(unsigned int hex, t_bool use_upper);

int	get_hex_len(unsigned long int n);

void	set_prefix_sign(t_number_format *format,
		t_format_config_modifier *modifier, int to_print_len)
{
    int adjusted_print_len;

    adjusted_print_len = to_print_len - ft_strlen("0x");
	format->hex_format.prefix_0x = TRUE;

	set_pad(&format->space_pad, modifier, adjusted_print_len, FALSE);
}

static t_number_format	build_hex_format(t_format_config *config,
		long long number, int to_print_len)
{
	int							i;
	t_number_format				format;
	t_format_config_modifier	current_modifier;

	init_number_format(&format, number);
	format.hex_format.initialized = TRUE;
	i = 0;
	while (i < config->modifiers_size)
	{
		current_modifier = config->modifiers[i];
		if (current_modifier.modifier_specifier == DIGIT
			|| current_modifier.modifier_specifier == ZERO
			|| current_modifier.modifier_specifier == MINUS)
			set_pad(&format.space_pad, &current_modifier, to_print_len, FALSE);
		if (current_modifier.modifier_specifier == DOT)
			set_max_width(&format, &current_modifier, to_print_len);
		if (current_modifier.modifier_specifier == SHARP)
			set_prefix_sign(&format, &current_modifier, to_print_len);
		i++;
	}
	return (format);
}

int	hex_printer(unsigned long int n, t_bool use_upper)
{
	int		i;
	int		printed;
	char	str[17];

	i = 0;
	printed = 0;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	while (n != 0)
	{
		str[i++] = (char)get_hex((int)(n % 16), use_upper);
		n /= 16;
	}
	while (--i >= 0)
		printed += ft_putchar_fd(str[i], 1);
	return (printed);
}

int	print_hex_max_width(long long n, t_number_format *format, t_bool show_minus)
{
	t_pad	pad;
	int		printed;

	printed = 0;
	(void)show_minus;
	pad = format->zero_pad;
	if (pad.padding_char == (char)ZERO && format->hex_format.prefix_0x)
		printed += print_hex_prefix((unsigned int)n,
				format->hex_format.use_upper);
	printed += print_repeat(pad.padding_char, pad.count);
	if (pad.padding_char == (char)SPACE && format->hex_format.prefix_0x)
		printed += print_hex_prefix((unsigned int)n,
				format->hex_format.use_upper);
	if (format->is_zero)
		return (printed);
	printed += hex_printer(n, format->hex_format.use_upper);
	return (printed);
}

int	print_hex(unsigned long int n, t_bool use_upper, t_format_config *config)
{
	int				n_len;
	int				printed;
	t_number_format	format;

	printed = 0;
	n_len = get_hex_len(n);
	format = build_hex_format(config, (long long)n, n_len);
	format.is_unsigned = TRUE;
	format.hex_format.use_upper = use_upper;
	printed += print_number_with_format((long long)n, &format,
			print_hex_max_width);
	return (printed);
}
