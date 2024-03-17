/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:36:36 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/17 22:11:00 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int				printed;
	t_format_config	format_config;

	printed = 0;
	while (*str)
	{
		if (*str == '%')
		{
			format_config = get_format_config(++str);
			str += format_config.format_len;
			continue ;
		}
		printed += ft_putchar_fd(*str++, 1);
	}
	return (printed);
}
