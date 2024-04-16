/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:27:29 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/15 07:19:52 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			set_sign(t_number_format *format,
					t_format_config_modifier *modifier, int to_print_len,
					t_bool is_negative);

void			set_pad(t_pad *pad, t_format_config_modifier *modifier,
					int to_print_len, t_bool is_negative);

void			set_max_width(t_number_format *format,
					t_format_config_modifier *modifier, int to_print_len);

t_number_format	build_number_format(t_format_config *config, long long number,
					int to_print_len, t_bool is_negative);

int				print_number_with_format(long long n, t_number_format *format,
					int (*printer)(long long, t_number_format *, t_bool));

int	unsigned_printer(unsigned int n)
{
	int		i;
	int		printed;
	char	str[11];

	printed = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	while (n != 0)
	{
		str[i++] = (char)((n % 10) + '0');
		n /= 10;
	}
	while (--i >= 0)
		printed += ft_putchar_fd(str[i], 1);
	return (printed);
}

int	print_unsigned_max_width(long long n, t_number_format *format,
		t_bool show_minus)
{
	t_pad	pad;
	int		printed;

	printed = 0;
	(void)show_minus;
	pad = format->zero_pad;
	printed += print_repeat(pad.padding_char, pad.count);
	if (format->is_zero)
		return (printed);
	printed += unsigned_printer(n);
	return (printed);
}

int	print_unsigned(unsigned int n, t_format_config *config)
{
	int				n_len;
	int				printed;
	t_number_format	format;

	printed = 0;
	n_len = get_int_len(ft_abs(n));
	format = build_number_format(config, n, n_len, FALSE);
	format.is_unsigned = TRUE;
	printed += print_number_with_format(n, &format, print_unsigned_max_width);
	return (printed);
}
