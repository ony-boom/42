/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:05:38 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/11 06:46:25 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_format_specifier	get_specifier(const char c)
{
	t_format_specifier			specifier;
	const t_format_specifier	*format_specifier_list = get_specifier_list();

	specifier = NOT_FOUND_SPECIFIER;
	while (*format_specifier_list)
	{
		if ((t_format_specifier)c == *format_specifier_list)
		{
			specifier = *format_specifier_list;
			break ;
		}
		format_specifier_list++;
	}
	return (specifier);
}

void	set_specifier_or_default(const char c, t_format_specifier *dest)
{
	t_format_specifier	specifier;

	specifier = get_specifier(c);
	if (specifier == NOT_FOUND_SPECIFIER)
		*dest = STR;
	else
		*dest = specifier;
}

void	init_format(t_format *format)
{
	format->modifier.pad.len = 0;
	format->modifier.pad.is_right = 0;
	format->modifier.pad.with_zero = 0;
}

int	get_format_len(char *str, int *format_len)
{
	int	len;

	len = 0;
	while (ft_isdigit(*str))
	{
		len++;
		str++;
	}
	*format_len += len;
	return (len);
}

t_format	get_format(const char *str, int *format_len)
{
	int					len;
	t_format			format;
	t_format_specifier	specifier;

	*format_len = 0;
	specifier = get_specifier(*str);
	init_format(&format);
	if (specifier != NOT_FOUND_SPECIFIER)
	{
		*format_len += 1;
		format.specifier = specifier;
		return (format);
	}
	if (*str == '-' || *str == '0')
	{
		format.modifier.pad.is_right = *str == '-';
		format.modifier.pad.with_zero = *str == '0';
		*format_len += 1;
		str++;
	}
	len = get_format_len((char *)str, format_len);
	str += len;
	set_specifier_or_default(*str, &format.specifier);
	format.modifier.pad.len = ft_atoi(str - len);
	return (format);
}
