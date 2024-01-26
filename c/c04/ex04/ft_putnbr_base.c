/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:46:03 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/26 16:38:41 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	has_char(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	base_has_error(char *base_like)
{
	if (has_char(base_like, '+') || has_char(base_like, '-'))
		return (1);
	while (*base_like)
	{
		if ((*base_like >= 0 && *base_like <= 32) || *base_like == 127)
			return (1);
		base_like++;
	}
	return (0);
}

int	get_base(char *base_like)
{
	int		c;
	char	curr;

	c = 0;
	if (!base_like[0] || !base_like[1])
		return (0);
	if (base_has_error(base_like))
		return (0);
	while (*base_like)
	{
		curr = *base_like;
		base_like++;
		if (has_char(base_like, curr))
			return (0);
		c++;
	}
	return (c);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char			c;
	unsigned int	int_base;
	unsigned int	as_unsigned;

	int_base = get_base(base);
	as_unsigned = nbr;
	if (!int_base)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (as_unsigned != 0)
	{
		ft_putnbr_base(nbr / int_base, base);
		c = base[nbr % int_base];
		ft_putchar(c);
	}
	else
    {
        ft_putchar('0');
    }
}
