/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 07:35:44 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/17 07:36:42 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				hex_printer(unsigned long int n, t_bool use_upper);
int				get_hex_len(unsigned long int n);

t_number_format	build_hex_format(t_format_config *config, long long number,
					int to_print_len);

int				print_number_with_format(long long n, t_number_format *format,
					int (*printer)(long long, t_number_format *, t_bool));

int	get_pointer_len(void *ptr)
{
	if (!ptr)
		return (ft_strlen("(nil)"));
	return (get_hex_len((unsigned long int)ptr) + 2);
}

static int	pointer_printer(void *pointer_like)
{
	uintptr_t	ptr;
	int			printed;

	printed = 0;
	ptr = (uintptr_t)pointer_like;
	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	printed += ft_putstr_fd("0x", 1);
	printed += hex_printer(ptr, FALSE);
	return (printed);
}

int	print_pointer_max_width(long long n, t_number_format *format,
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
	printed += pointer_printer((void *)n);
	return (printed);
}

int	print_pointer(void *n, t_format_config *config)
{
	int				n_len;
	int				printed;
	t_number_format	format;

	printed = 0;
	n_len = get_pointer_len((void *)n);
	format = build_hex_format(config, (long long int)n, n_len);
	format.is_unsigned = TRUE;
	printed += print_number_with_format((long long int)n, &format,
			print_pointer_max_width);
	return (printed);
}
