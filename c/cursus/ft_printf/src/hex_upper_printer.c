/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_upper_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:31:52 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/05 19:25:56 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_upper_hex(va_list params)
{
	return (hex_base_printf(params, 1));
}

t_printer	*hex_upper_printer(void)
{
	return (printer_new(UPPER_HEX, print_upper_hex));
}
