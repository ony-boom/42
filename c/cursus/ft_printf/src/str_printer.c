/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:36:57 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/21 22:36:32 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	str_print_fn(void *character)
{
	char	*str;

	str = (char *)character;
	return (ft_putstr_fd(str, 1));
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

	if (!str)
		return (ft_putstr_fd("(null)", 1));

	printed = 0;
	modifier = config.modifier_config;
	pad = modifier.pad.len - ft_strlen(str);
	if (!config.has_config)
		return (ft_putstr_fd(str, 1));
	if (config.modifier_config.pad.is_dot)
		return (printn_str(str, config.modifier_config.pad.len));
	if (pad <= 0)
		return (ft_putstr_fd(str, 1));
	printed += print_pad(get_print_pad_params(str, pad, ' ',
				modifier.pad.is_right), str_print_fn);
	return (printed);
}
