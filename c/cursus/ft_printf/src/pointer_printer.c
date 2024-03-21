/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:51:29 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/22 00:05:01 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

static int	get_pointer_len(void *ptr)
{
	int					len;
	unsigned long int	temp;

	len = 0;
	temp = (unsigned long int)ptr;
	while (temp != 0)
	{
		len++;
		temp /= 16;
	}
	return (len + 2);
}

static int	pointer_printer(void *pointer_like)
{
	int			shift;
	int			printed;
	uintptr_t	ptr;

	printed = 0;
	ptr = (uintptr_t)pointer_like;
	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	printed += ft_putstr_fd("0x", 1);
	shift = (sizeof(ptr) << 3) - 4;
	while (shift >= 0 && ((ptr >> shift) & 0xf) == 0)
		shift -= 4;
	while (shift >= 0)
	{
		printed += ft_putchar_fd(get_hex((ptr >> shift) & 0xf, 0), 1);
		shift -= 4;
	}
	return (printed);
}

int	pointer_printer_fn(void *p_pointer_like)
{
	void	*pointer_like;

	pointer_like = *(void **)p_pointer_like;
	return (pointer_printer(pointer_like));
}

int	print_ptr(void *ptr, t_format_config config)
{
	int							pad;
	int							printed;
	t_format_modifier_config	modifier;

	printed = 0;
	modifier = config.modifier_config;
	pad = modifier.pad.len - get_pointer_len(ptr);
	if (!config.has_config || (pad <= 0 && !config.modifier_config.pad.is_dot))
		return (pointer_printer(ptr));
	printed += print_pad(get_print_pad_params(&ptr, pad, ' ',
				modifier.pad.is_right), pointer_printer_fn);
	return (printed);
}
