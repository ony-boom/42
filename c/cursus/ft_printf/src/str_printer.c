/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:36:57 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/19 22:04:00 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int str_printer(char *str)
{
	if (!str || !*str)
	{
		if (!str)
			return (ft_putstr_fd("(null)", 1));
		return (0);
	}
	return (ft_putstr_fd(str, 1));
}

static int	str_print_fn(void *character)
{
	char	*str;

	str = (char *)character;
	return (str_printer(str));
}

int	print_str(char *str, t_format_config config)
{
	int							pad;
	int							printed;
	t_format_modifier_config	modifier;

	printed = 0;
	modifier = config.modifier_config;
	pad = modifier.pad.len - ft_strlen(str);
	if (!config.has_config || pad <= 0)
		return (str_printer(str));
	printed += print_pad(
		(t_print_pad_params){
			.rest = str,
			.padding_count = pad,
			.padding_char = ' ',
			.is_right = modifier.pad.is_right,
		},
		str_print_fn);
	return (printed);
}
