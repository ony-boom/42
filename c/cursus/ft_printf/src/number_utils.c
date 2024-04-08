/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:17:22 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/08 15:12:47 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_number_format(t_number_format *format)
{
	format->sign = (t_format_sign){.show = FALSE, .positive_sign = '+'};
	format->space_pad = (t_pad){.count = 0, .padding_char = ' ',
		.from_right = FALSE};
	format->zero_pad = (t_pad){.count = 0, .padding_char = '0',
		.from_right = FALSE};
}

void	set_pad(t_pad *pad, t_format_config_modifier *modifier,
		int to_print_len, t_bool is_negative)
{
	pad->padding_char = ' ';
	if (modifier->modifier_specifier == ZERO)
		pad->padding_char = '0';
	pad->count = modifier->value - to_print_len
		- (int)(modifier->modifier_specifier == PLUS
			|| modifier->modifier_specifier == SPACE) - (int)is_negative;
	if (pad->count <= 0)
		pad->count = 0;
	pad->from_right = (t_bool)(modifier->modifier_specifier == MINUS);
}

void	set_max_width(t_number_format *format,
		t_format_config_modifier *modifier, int to_print_len)
{
	format->zero_pad.count = modifier->value - to_print_len;
	if (format->zero_pad.count <= 0)
		format->zero_pad.count = 0;
	format->zero_pad.from_right = FALSE;
	format->zero_pad.padding_char = '0';
	format->space_pad.count -= format->zero_pad.count;
	if (format->space_pad.count <= 0)
		format->space_pad.count = 0;
}

void	set_sign(t_number_format *format, t_format_config_modifier *modifier,
		int to_print_len, t_bool is_negative)
{
	set_pad(&format->space_pad, modifier, to_print_len, is_negative);
	format->sign.show = TRUE;
	if (modifier->modifier_specifier == SPACE)
		format->sign.positive_sign = ' ';
}
