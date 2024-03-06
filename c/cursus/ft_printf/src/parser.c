/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:05:38 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/06 14:18:13 by rony-lov         ###   ########.fr       */
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

t_format	*get_format(const char *str, int *format_len)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (!format)
		return (NULL);
	format->specifier = get_specifier(*str);
	// at this point `str` is something like 👉️ s|d|x|i
	// + the rest of the string
	format->modifier = get_modifier(str++, format_len);
	// at this point `str` like the above but without the specifier
	*format_len += 1;
	return (format);
}

void	free_format(t_format *format)
{
	if (!format)
		return ;
	free(format->modifier);
	free(format);
}
