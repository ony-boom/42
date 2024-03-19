/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 06:35:56 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/19 21:46:15 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	char_print_fn(void *character)
{
	char	c;

	c = *(char *)character;
	return (ft_putchar_fd(c, 1));
}

int	print_char(char c, t_format_config config)
{
	int							pad;
	int							printed;
	char						padding;
	t_format_modifier_config	modifier;

	printed = 0;
	padding = ' ';
	modifier = config.modifier_config;
	pad = modifier.pad.len - 1;
	if (!config.has_config || pad <= 0)
		return (ft_putchar_fd(c, 1));
	if (modifier.pad.is_zero)
		padding = '0';
	printed += print_pad(
		(t_print_pad_params){
			.rest = &c,
			.padding_count = pad,
			.padding_char = padding,
			.is_right = modifier.pad.is_right,
		},
		char_print_fn);
	return (printed);
}
