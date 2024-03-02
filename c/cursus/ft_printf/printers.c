/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:12:13 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/02 12:15:11 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_printer	*Printer_new(t_format specifier, print_fn fn)
{
	t_printer	*printer;

	printer = malloc(sizeof(t_printer));
	if (!printer)
		return (NULL);
	printer->format_specifier = specifier;
	printer->fn = fn;
	return (printer);
}

const t_printer	**get_printers(void)
{
	const t_printer	**printers = ft_calloc(PRINTER_LIST_SIZE,
				sizeof(t_printer));

	if (!printers)
		return (NULL);
	printers[0] = char_printer();
	printers[1] = int_printer();
	return (printers);
}

const t_printer	*get_printer_at_format(const t_printer **printers,
		t_format format)
{
	while (*printers && format != (*printers)->format_specifier)
		printers++;
	return (*printers);
}
