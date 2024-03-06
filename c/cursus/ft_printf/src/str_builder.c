/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:17:47 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/06 15:59:48 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*build_int_format_str(t_format_modifier *modifier, int value)
{
	if (!modifier)
		return NULL;
}

char	*new_str_builder(t_format *format, va_list params)
{
	if (!format)
		return NULL;
	if (format->specifier == DECIMAL || format->specifier == INTEGER)
	{
		return build_int_format_str(format->modifier, va_arg(params, int));
	}
}
