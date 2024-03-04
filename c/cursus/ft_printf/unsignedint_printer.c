/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignedint_printer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:34:37 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/03 14:38:29 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	printer(va_list params)
{
	unsigned int	n;

	n = ft_abs(va_arg(params, int));
	return (ft_putnbr_fd(n, 1));
}

t_printer	*unsignedint_printer(void)
{
	return (printer_new(UNSIGNED_INT, printer));
}
