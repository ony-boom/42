/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:12:24 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/02 13:56:00 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int nb, int fd)
{
	int	printed;

	printed = 0;
	if (nb == -2147483648)
	{
		printed += ft_putchar_fd('-', fd);
		printed += ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	if (nb < 0)
	{
		printed += ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
	{
		printed += ft_putnbr_fd(nb / 10, fd);
		printed += ft_putnbr_fd(nb % 10, fd);
	}
	else
		printed += ft_putchar_fd(nb + '0', fd);
	return (printed);
}
