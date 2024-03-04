/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:25:01 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/02 19:32:45 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	printer(va_list params)
{
	char	*str;

	str = va_arg(params, char *);
	if (!str || !*str)
	{
		if (!str)
			return (ft_putstr_fd("(null)", 1));
		return (0);
	}
	return (ft_putstr_fd(str, 1));
}

t_printer	*str_printer(void)
{
	return (printer_new(STR, printer));
}
