/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:21:44 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/20 16:49:53 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	digit_print_fn(void *p_digit)
{
	int	digit;

	digit = *(int *)p_digit;
	return (ft_putnbr_fd(digit, 1));
}

int	print_digit(int digit, t_format_config config)
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
		return (ft_putnbr_fd(digit, 1));
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
