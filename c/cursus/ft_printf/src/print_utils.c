/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:40:59 by rony-lov          #+#    #+#             */
/*   Updated: 2024/04/07 19:02:30 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_repeat(char c, int count)
{
	int	printed;

	printed = 0;
	while (printed < count)
		printed += ft_putchar_fd(c, 1);
	return (printed);
}
