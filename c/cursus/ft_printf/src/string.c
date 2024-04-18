/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 07:37:05 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/18 08:19:06 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_n_str(char *str, int max_len)
{
	int	i;

	i = 0;
	while (i < max_len && *str)
		i += ft_putchar_fd(*str++, 1);
	return (i);
}

void	init_str_format(t_str_format_config *format, int str_len, char *str)
{
	format->str = str;
	format->pad = (t_pad){.count = 0, .padding_char = ' ', .from_right = FALSE,
		.initialized = FALSE};
	format->precision = str_len;
}

t_str_format_config	build_str_format(t_format_config *config, int len,
		char *str)
{
	int							i;
	t_str_format_config			format;
	t_format_config_modifier	current_modifier;

	i = 0;
	init_str_format(&format, len, str);
	while (i < config->modifiers_size)
	{
		current_modifier = config->modifiers[i];
		if (current_modifier.modifier_specifier == DIGIT
			|| current_modifier.modifier_specifier == SPACE
			|| current_modifier.modifier_specifier == MINUS)
			set_base_pad(&format.pad, &current_modifier, len
				- (int)(current_modifier.modifier_specifier == SPACE), FALSE);
		if (current_modifier.modifier_specifier == DOT)
		{
			format.precision = current_modifier.value;
			if (format.precision < format.pad.original_value)
				format.pad.count = format.pad.original_value - format.precision;
		}
		i++;
	}
	return (format);
}

int	print_str(char *str, t_format_config *config)
{
	int					len;
	int					printed;
	char				*base_str;
	t_str_format_config	format;

	base_str = str;
	printed = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	format = build_str_format(config, len, str);
	if (format.precision < len && !base_str)
		format.str = "";
	if (format.pad.from_right)
	{
		printed += print_n_str(format.str, format.precision);
		printed += print_repeat(format.pad.padding_char, format.pad.count);
	}
	else
	{
		printed += print_repeat(format.pad.padding_char, format.pad.count);
		printed += print_n_str(format.str, format.precision);
	}
	return (printed);
}
