/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:05:50 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/09 07:05:36 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	set_pad(t_pad *pad, t_format_config_modifier *modifier)
{
	pad->padding_char = ' ';
	pad->count = modifier->value - 1;
	if (pad->count <= 0)
		pad->count = 0;
	pad->from_right = (t_bool)(modifier->modifier_specifier == MINUS);
}

static t_pad	build_format(t_format_config *config)
{
	t_pad						pad;
	t_format_config_modifier	current_modifier;

	pad.count = 0;
	pad.padding_char = ' ';
	pad.from_right = FALSE;
	current_modifier = config->modifiers[0];
	if (is_pad_modifier(current_modifier.modifier_specifier, config->specifier))
		set_pad(&pad, &current_modifier);
	return (pad);
}

int	print_char(char c, t_format_config *config)
{
	int		printed;
	t_pad	pad;

	printed = 0;
	pad = build_format(config);
	if (pad.from_right)
	{
		printed += ft_putchar_fd(c, 1);
		printed += print_repeat(pad.padding_char, pad.count);
	}
	else
	{
		printed += print_repeat(pad.padding_char, pad.count);
		printed += ft_putchar_fd(c, 1);
	}
	return (printed);
}
