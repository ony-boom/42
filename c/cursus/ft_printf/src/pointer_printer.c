/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:49:48 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/05 19:26:22 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_ptr(void *pointer_like)
{
	int			shift;
	int			printed;
	uintptr_t	ptr;

	printed = 0;
	ptr = (uintptr_t)pointer_like;
	if (!ptr)
	{
		printed += ft_putstr_fd("(nil)", 1);
		return (printed);
	}
	printed += ft_putstr_fd("0x", 1);
	shift = (sizeof(ptr) << 3) - 4;
	// this next while loop is used to only show
	// the most non-zero important nibbles
	while (shift >= 0 && ((ptr >> shift) & 0xf) == 0)
		shift -= 4;
	while (shift >= 0)
	{
		printed += ft_putchar_fd(get_hex((ptr >> shift) & 0xf, 0), 1);
		shift -= 4;
	}
	return (printed);
}

int	printer(va_list params)
{
	return (print_ptr(va_arg(params, void *)));
}

t_printer	*pointer_printer(void)
{
	return (printer_new(POINTER, printer));
}
