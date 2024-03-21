/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:22:08 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/21 13:21:34 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_hex(int n, int use_upper)
{
	char	c;

	if (n < 10)
		return ('0' + n);
	else
	{
		c = 'a';
		if (use_upper)
			c = 'A';
		return (c + n - 10);
	}
}

int get_hex_len(unsigned int n) {
  int len;

  len = 0;
  while ((int)n > 0) {
    n /= 16;
    len++;
  }
  return len;
}

int print_hex_prefix(t_bool use_upper)
{
	if (use_upper)
		return ft_putstr_fd("0X", 1);
	else
		return ft_putstr_fd("0x", 1);
}

int	print_repeat(char c, int count)
{
	int	printed;

	printed = 0;
	while (printed < count)
		printed += ft_putchar_fd(c, 1);
	return (printed);
}

t_print_pad_params	get_print_pad_params(void *rest, int pad_count,
		char padding_char, t_bool is_right)
{
	t_print_pad_params	params;

	params.rest = rest;
	params.is_right = is_right;
	params.padding_count = pad_count;
	params.padding_char = padding_char;
	return (params);
}
