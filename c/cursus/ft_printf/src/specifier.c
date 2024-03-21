/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:45:33 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/20 18:29:32 by rony-lov         ###   ########.fr       */
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
