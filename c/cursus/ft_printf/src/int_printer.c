/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:51:08 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/05 19:26:03 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	printer(va_list params)
{
	return (ft_putnbr_fd((va_arg(params, int)), 1));
}

t_printer	*int_printer(void)
{
	return (printer_new(INTEGER, printer));
}
