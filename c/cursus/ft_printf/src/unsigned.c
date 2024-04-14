/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:27:29 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/09 06:40:51 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	unsigned_printer(unsigned int n)
{
	int	printed;

	printed = 0;
	if (n >= 10)
	{
		printed += unsigned_printer((n / 10));
		printed += unsigned_printer((n % 10));
	}
	else
		printed += ft_putchar_fd(n + '0', 1);
	return (printed);
}
