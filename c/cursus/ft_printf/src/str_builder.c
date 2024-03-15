/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 06:41:55 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/13 07:28:18 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

int	is_int_specifier(t_format_specifier specifier)
{
	return (specifier == DECIMAL || specifier == UNSIGNED_INT
		|| specifier == INTEGER);
}

static char *pad(t_format format, char *str, int diff, int str_len)
{
    int		size;
    char *padded;

    size = str_len + diff + 1;
    padded = ft_calloc(size, sizeof(char));
    if (!padded)
        return (NULL);
    if (format.modifier.pad.is_right)
    {
        ft_memcpy(padded, str, str_len);
        ft_memset(padded + str_len - 1, ' ', diff);
        return (padded);
    }
    if (format.modifier.pad.with_zero && is_int_specifier(format.specifier))
        ft_memset(padded, '0', diff);
    else
        ft_memset(padded, ' ', diff);
    ft_strlcat(padded, str, size);
    return (padded);
}

static char	*apply_pad(t_format format, char *str, int str_len)
{
	int		diff;
    char *base_str;

    base_str = ft_strdup(str);
	diff = (format.modifier.pad.len - str_len + 1);
	if (diff > 0)
    {
        free(base_str);
        return pad(format, str, diff, str_len);
    }
	return base_str;
}

static char	*apply_modifier(t_format format, char *base_str)
{
	int	base_str_len;
	int	modified_str_len;

	if (!base_str)
		return (NULL);
	base_str_len = ft_strlen(base_str);
	modified_str_len = base_str_len + 1;
	if (format.modifier.pad.len)
		return (apply_pad(format, base_str, modified_str_len));
	return (ft_strdup(base_str));
}

char	*new_str_builder(t_format format, va_list params)
{
	char	*str;
	char	*result;

	if (format.specifier == DECIMAL || format.specifier == INTEGER)
		str = ft_itoa(va_arg(params, int));
	else if (format.specifier == CHAR || format.specifier == PERCENT)
		str = char_to_str(va_arg(params, int));
	else if (format.specifier == HEX || format.specifier == UPPER_HEX)
		str = hex_to_str(va_arg(params, unsigned int),
				format.specifier == UPPER_HEX);
	else if (format.specifier == POINTER)
		str = pointer_to_str(va_arg(params, void *));
	else if (format.specifier == UNSIGNED_INT)
		str = unsigned_to_str(va_arg(params, unsigned int));
	else
		str = ft_strdup(va_arg(params, char *));
	result = (apply_modifier(format, str));
	free(str);
	return (result);
}
