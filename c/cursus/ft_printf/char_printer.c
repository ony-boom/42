/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:21:31 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/02 14:29:53 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	printer(va_list params)
{
	return (ft_putchar_fd(va_arg(params, int), 1));
}

t_printer	*char_printer(void)
{
	return (printer_new(CHAR, printer));
}
