/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:43:41 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/09 22:14:28 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_pad_conf	get_pad_conf(const char *str)
{
	int			substr_end;
	t_pad_conf	pad_conf;

	substr_end = 0;
	pad_conf.len = 0;
	if (*str == '-' || *str == '0')
	{
		pad_conf.is_right = *str == '-';
		pad_conf.with_zero = *str == '0';
		str++;
	}
	while (ft_isdigit(*str++))
		substr_end++;
	pad_conf.len = ft_atoi(str - (substr_end + 1));
	return (pad_conf);
}

t_format_modifier	get_modifier(const char *str)
{
	t_format_modifier	modifier;

	modifier.pad = get_pad_conf(str);
	return (modifier);
}
