/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:51:31 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/07 19:02:23 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	parse_number_value(char *format, t_format_config_modifier *modifier)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (ft_isdigit(format[i]))
	{
		value = value * 10 + (format[i] - '0');
		i++;
	}
	modifier->value = value;
	modifier->len += i;
	return (modifier->len);
}

int	parse_modifier(char *format, t_format_config_modifier *modifier)
{
	modifier->len = 0;
	modifier->modifier_specifier = 0;
	if (is_valid_format_modifier(format[0]))
		modifier->modifier_specifier = (t_format_modifier)format[0];
	else if (ft_isdigit(format[0]))
		modifier->modifier_specifier = DIGIT;
	if (modifier->modifier_specifier == DIGIT)
		return (parse_number_value(format, modifier));
	modifier->len++;
	return (parse_number_value(++format, modifier));
}

void	init_config(t_format_config *format_config)
{
	format_config->len = 0;
	format_config->specifier = STR;
	format_config->modifiers = ft_calloc(MAX_MODIFIER_COUNT,
			sizeof(t_format_config_modifier));
}

int	trim_format(char *format)
{
	int	count;

	count = 0;
	while (is_valid_format_modifier(format[count]))
		count++;
	if (count)
		count--;
	return (count);
}

t_format_config	new_format_config(char *format)
{
	int i;
	int modifier_index;
	t_format_config format_config;

	i = trim_format(format);
	modifier_index = 0;
	init_config(&format_config);
	while (format[i] && !is_valid_format_specifier(format[i]))
	{
		if (ft_isdigit(format[i]) || is_valid_format_modifier(format[i]))
		{
			i += parse_modifier(format + i,
					&format_config.modifiers[modifier_index]);
			modifier_index++;
			continue ;
		}
		i++;
	}
	format_config.len = i;
	if (is_valid_format_specifier(format[i]))
	{
		format_config.specifier = (t_format_specifier)(format[i]);
		format_config.len++;
	}
	format_config.modifiers_size = modifier_index;
	return (format_config);
}