/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:21:31 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/02 12:08:56 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

static void	printer(va_list params)
{
	ft_putchar_fd(va_arg(params, int), 1);
}

t_printer	*char_printer(void)
{
	return (Printer_new(CHAR, printer));
}
