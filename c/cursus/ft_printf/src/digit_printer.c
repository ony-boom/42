/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:21:44 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/20 09:24:07 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int	print_digit(int *digit, t_bool is_unsigned ,t_format_config config)
{
	int							pad;
	int							printed;
	t_format_modifier_config	modifier;

	printed = 0;
	modifier = config.modifier_config;
	pad = modifier.pad.len - get_int_len(*digit);
	if (!config.has_config)
		return (ft_putnbr_fd(*digit, 1));
	/* if(config.modifier_config.max_width)
		return printn_str(str, config.modifier_config.max_width);
	if (pad <= 0)
		return (str_printer(str));
	printed += print_pad(
		(t_print_pad_params){
			.rest = str,
			.padding_count = pad,
			.padding_char = ' ',
			.is_right = modifier.pad.is_right,
		},
		str_print_fn); */
	return (printed);
}
