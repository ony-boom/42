/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:51:08 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/02 11:53:25 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	printer(va_list params)
{
	ft_putnbr_fd((va_arg(params, int)), 1);
}

t_printer	*int_printer(void)
{
	return (Printer_new(INTEGER, printer));
}
