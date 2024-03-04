/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:39:21 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/04 07:00:36 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	printer(va_list params)
{
	(void)params;
	return (ft_putchar_fd('%', 1));
}

t_printer	*percent_printer(void)
{
	return (printer_new(PERCENT, printer));
}
