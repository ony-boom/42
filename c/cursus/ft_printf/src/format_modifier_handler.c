/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_modifier_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:22:43 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/19 08:13:49 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_pad_len(char *format, int *format_len)
{
	char *temp;
	temp = format;
	char *pad_len;
	int pad_len_as_int;

	while (ft_isdigit(*temp))
	{
		temp++;
		*format_len += 1;
	}
	pad_len = ft_substr(format, 0, *format_len - 1);
	pad_len_as_int = ft_atoi(pad_len);
	free(pad_len);
	return pad_len_as_int;
}

t_pad_modifier	get_pad_modifier(char *format, int *format_len)
{
	t_pad_modifier	pad;

	pad.is_zero = *format == '0';
	pad.is_right = *format == '-';
	format += pad.is_zero || pad.is_right;
	pad.len = get_pad_len(format, format_len);
	return (pad);
}

t_int_modifier	get_int_modifier(const char *format, int *format_len)
{
	t_int_modifier	int_modifier;

	*format_len += 1;
	int_modifier.show_sign = TRUE;
	int_modifier.use_space_for_positive = *format == SPACE;
	return (int_modifier);
}

int	get_max_width(char *format, int *format_len)
{
	format++;
	*format_len += 1;
	return (get_pad_len(format, format_len));
}
