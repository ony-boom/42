/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:59:33 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/03 14:39:46 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	printer(va_list params)
{
	return (ft_putnbr_fd((va_arg(params, int)), 1));
}

t_printer	*decimal_printer(void)
{
	return (printer_new(DECIMAL, printer));
}
