/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:05:38 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/09 23:00:31 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

const t_format_specifier	*get_specifier_list(void)
{
	static const t_format_specifier	specifier_list[SPECIFER_LIST_SIZE] = {CHAR,
			INTEGER, STR, DECIMAL, POINTER, UNSIGNED_INT, HEX, UPPER_HEX,
			PERCENT};

	return (specifier_list);
}

t_format_specifier	get_specifier(const char c)
{
	t_format_specifier			specifier;
	const t_format_specifier	*format_specifier_list = get_specifier_list();

		printf("specifier ==> %c\n", c);
	specifier = *format_specifier_list;
	while (*format_specifier_list && (t_format_specifier)c != specifier)
		specifier = *format_specifier_list++;
	return (specifier);
}

t_format	get_format(const char *str, int *format_len)
{
	t_format	format;

	format.specifier = get_specifier(*str++);
	format.modifier = get_modifier(str++);
	*format_len += format.modifier.pad.len + 1;
	return (format);
}
