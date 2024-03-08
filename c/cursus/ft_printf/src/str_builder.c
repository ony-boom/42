/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:17:47 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/07 09:16:08 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char *apply_modifier(t_format_modifier modifier, char *base_str)
{
	char *modified_str;
	int base_str_len;
	int modified_str_len;

	if (base_str)
		return NULL;
	
	modified_str = base_str;
	base_str_len = ft_strlen(base_str);
	modified_str_len = base_str_len + 1;


	return modified_str;
}

char	*new_str_builder(t_format format, va_list params)
{
	char *str;
	if (format.specifier == DECIMAL || format.specifier == INTEGER)
		str = ft_itoa(va_arg(params, int));

	return apply_modifier(format.modifier, str);
}
