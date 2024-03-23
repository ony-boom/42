/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:51:29 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/23 14:18:56 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

static int	get_pointer_len(void *ptr)
{
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
