/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:05:38 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/05 22:58:53 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_format_specifier	get_specifier(const char c)
{
	t_format_specifier			specifier;
	const t_format_specifier	*format_specifier_list = get_specifier_list();

	specifier = *format_specifier_list;
	while (*format_specifier_list && c != specifier)
		specifier = *format_specifier_list++;
	return (specifier);
}


t_format	*get_format(const char *str)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (!format)
		return (NULL);
	format->specifier = get_specifier(*str);
	format->modifier = get_modifier(str++);
	return (format);
}

void free_format(t_format *format)
{
	if (!format)
		return;
	free(format->modifier);
	free(format);
}
