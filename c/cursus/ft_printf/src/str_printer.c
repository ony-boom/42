/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:36:57 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/20 16:49:06 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	str_printer(char *str)
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

static int	printn_str(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n && *str)
		i += ft_putchar_fd(*str++, 1);
	return (i);
}

int	print_str(char *str, t_format_config config)
{
	int							pad;
	int							printed;
	t_format_modifier_config	modifier;

	printed = 0;
	modifier = config.modifier_config;
	pad = modifier.pad.len - ft_strlen(str);
	if (!config.has_config)
		return (str_printer(str));
	if (config.modifier_config.pad.is_dot)
		return (printn_str(str, config.modifier_config.pad.len));
	if (pad <= 0)
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
