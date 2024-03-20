/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_modifier_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:22:43 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/20 16:58:23 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_pad_len(char *format, int *format_len)
{
	char	*temp;
	int		pad_len_as_int;

	temp = format;
	pad_len_as_int = 0;
	while (ft_isdigit(*temp))
	{
		pad_len_as_int = pad_len_as_int * 10 + (*temp - '0');
		temp++;
		(*format_len)++;
	}
	return (pad_len_as_int);
}

static int	get_max_width(char *format, int *format_len)
{
	if (!ft_isdigit(*format))
		return -1;
	return (get_pad_len(format, format_len));
}

t_pad_modifier	get_pad_modifier(char *format, int *format_len)
{
	t_pad_modifier	pad;
	
	pad.is_zero = *format == '0';
	pad.is_right = *format == '-';
	pad.is_dot = *format == '.';
	format += pad.is_zero || pad.is_right || pad.is_dot;
	if (pad.is_dot)
		pad.len = get_max_width(format, format_len);
	else
		pad.len = get_pad_len(format, format_len);
	return (pad);
}

t_int_modifier	get_int_modifier(const char *format, int *format_len)
{
	t_int_modifier	int_modifier;

	(void)format_len;
	int_modifier.show_sign = TRUE;
	int_modifier.use_space_for_positive = *format == SPACE;
	return (int_modifier);
}
