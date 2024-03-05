/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:12:13 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/05 19:26:29 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printer	*printer_new(t_format specifier, t_print_fn fn)
{
	t_printer	*printer;

	printer = malloc(sizeof(t_printer));
	if (!printer)
		return (NULL);
	printer->format_specifier = specifier;
	printer->fn = fn;
	return (printer);
}

static t_printer	**get_printers(void)
{
	t_printer	**printers;

	printers = ft_calloc(PRINTER_LIST_SIZE, sizeof(t_printer));
	if (!printers)
		return (NULL);
	return (printers);
}

void	register_printer(t_printer **registry, t_printer *printer)
{
	int	i;

	i = 0;
	while (registry[i])
		i++;
	if (i < PRINTER_LIST_SIZE)
		registry[i] = printer;
}

t_printer	**init_printers(void)
{
	t_printer	**printers;

	printers = get_printers();
	register_printer(printers, char_printer());
	register_printer(printers, int_printer());
	register_printer(printers, str_printer());
	register_printer(printers, decimal_printer());
	register_printer(printers, unsignedint_printer());
	register_printer(printers, hex_lower_printer());
	register_printer(printers, hex_upper_printer());
	register_printer(printers, percent_printer());
	register_printer(printers, pointer_printer());
	return (printers);
}

t_printer	*get_printer_at_format(t_printer **printers, t_format format)
{
	while (*printers && format != (*printers)->format_specifier)
		printers++;
	return (*printers);
}
