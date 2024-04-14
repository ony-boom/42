/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:27:29 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/14 19:09:47 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_sign(t_number_format *format, t_format_config_modifier *modifier,
		int to_print_len, t_bool is_negative);

void					set_pad(t_pad *pad, t_format_config_modifier *modifier,
							int to_print_len, t_bool is_negative);

void					set_max_width(t_number_format *format,
							t_format_config_modifier *modifier,
							int to_print_len);

t_number_format	build_number_format(t_format_config *config, int number,
		int to_print_len, t_bool is_negative);


int	unsigned_printer(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
	{
		printed += unsigned_printer((n / 10));
		printed += unsigned_printer((n % 10));
	}
	else
		printed += ft_putchar_fd(n + '0', 1);
	return (printed);
}

t_number_format print_unsigned(unsigned int n, t_format_config *config)
{
	int				n_len;
	int				printed;
	t_number_format	format;

	printed = 0;
	n_len = get_int_len(ft_abs(n));
	format = build_number_format(config, n, n_len, (t_bool)(n < 0));

	return format;
}
