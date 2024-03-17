/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:45:33 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/17 22:59:05 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	is_valid_format_specifier(char c)
{
	const t_format_specifier	specifiers[] = {
		CHAR,
		INTEGER,
		STR,
		DECIMAL,
		POINTER,
		UNSIGNED_INT,
		HEX,
		UPPER_HEX,
		PERCENT
	};
	int							num_specifiers;

	num_specifiers = sizeof(specifiers) / sizeof(specifiers[0]);
	return (is_valid_char(c, (const char *)specifiers, num_specifiers));
}

t_bool	is_valid_format_modifier(char c)
{
	const t_format_modifier	modifiers[] = {
		MINUS,
		ZERO,
		DOT,
		SHARP,
		SPACE,
		PLUS
	};
	int						num_modifiers;

	num_modifiers = sizeof(modifiers) / sizeof(modifiers[0]);
	return (is_valid_char(c, (const char *)modifiers, num_modifiers));
}
