/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:22:08 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/18 08:21:12 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	is_valid_format_specifier(char c)
{
	const t_format_specifier	specifiers[] = {CHAR, INTEGER, STR, DECIMAL,
		POINTER, UNSIGNED_INT, HEX, UPPER_HEX, PERCENT};
	int							i;
	int							size;

	i = 0;
	size = sizeof(specifiers) / sizeof(specifiers[0]);
	while (i < size)
	{
		if (specifiers[i] == (t_format_specifier)c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	is_valid_format_modifier(char c)
{
	const t_format_modifier	modifiers[] = {MINUS, ZERO, DOT, SHARP, SPACE,
		PLUS};
	int						i;
	int						size;

	i = 0;
	size = sizeof(modifiers) / sizeof(modifiers[0]);
	while (i < size)
	{
		if (modifiers[i] == (t_format_modifier)c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	is_pad_modifier(t_format_modifier modifier,
		t_format_specifier specifier)
{
	return ((t_bool)((modifier == DIGIT || modifier == MINUS
			|| modifier == ZERO) || (modifier == SPACE
			&& specifier == STR)));
}

int	trim_format(char *format)
{
	int					count;
	t_format_modifier	to_trim;

	count = 0;
	to_trim = (t_format_modifier)format[0];
	while (is_valid_format_modifier(format[count])
		&& (t_format_modifier)format[count] == to_trim)
		count++;
	if (count)
		count--;
	return (count);
}

void	set_base_pad(t_pad *pad, t_format_config_modifier *modifier,
		int to_print_len, t_bool is_negative)
{
	pad->original_value = modifier->value;
	pad->initialized = TRUE;
	pad->padding_char = ' ';
	if (modifier->modifier_specifier == ZERO)
		pad->padding_char = '0';
	pad->count = (modifier->value - to_print_len
			- (int)(modifier->modifier_specifier == PLUS
				|| modifier->modifier_specifier == SPACE)) - (int)is_negative;
	if (pad->count <= 0)
		pad->count = 0;
	pad->from_right = (t_bool)(modifier->modifier_specifier == MINUS);
}
