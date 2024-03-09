/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:15:49 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/09 23:01:39 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	print_formatted(char *str, int *format_len, va_list params)
{
	t_format	format;
	// char		*formatted_str;

	format = get_format(str, format_len);
	(void)(params);
	// formatted_str = new_str_builder(format, params);
	printf("specifier: %c", format.specifier);
	// printf("{format.pad: {.len: %d, .with_zero: %d, .is_right: %d}}\n", format.modifier.pad.len, format.modifier.pad.with_zero, format.modifier.pad.is_right);
	return (0);
}
