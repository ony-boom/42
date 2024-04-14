/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:51:31 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/09 07:11:39 by rony-lov         ###   ########.fr       */
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

t_format_config	new_format_config(char *format)
{
	int				i;
	int				mod_i;
	t_format_config	format_config;

	mod_i = 0;
	i = trim_format(format);
	init_config(&format_config);
	while (format[i] && !is_valid_format_specifier(format[i]))
	{
		if (ft_isdigit(format[i]) || is_valid_format_modifier(format[i]))
		{
			i += parse_modifier(format + i, &format_config.modifiers[mod_i]);
			mod_i++;
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
	format_config.modifiers_size = mod_i;
	return (format_config);
}
