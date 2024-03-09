/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:38:05 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/09 09:21:27 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_hex(int n, int use_upper)
{
	char	c;

	if (n < 10)
		return ('0' + n);
	else
	{
		c = 'a';
		if (use_upper)
			c = 'A';
		return (c + n - 10);
	}
}

int	get_hex_len(unsigned int n)
{
	unsigned int	i;
	int				len;
	int				shift;
	int				digit;

	i = 0;
	len = 0;
	shift = (sizeof(n) << 3) - 4;
	while (i < sizeof(n) * 2)
	{
		digit = (n >> shift) & 0xf;
		if (digit != 0 || len > 0)
			len++;
		shift -= 4;
		++i;
	}
	return (len);
}

void	set_hexstr(unsigned int n, int use_upper, char *dst)
{
	static const unsigned int	base = 16;

	if (n >= base)
	{
		set_hexstr((n / base), use_upper, dst);
		set_hexstr((n % base), use_upper, dst);
	}
	else
		*dst++ = ft_putchar_fd(get_hex(n, use_upper), 1);
}

char	*hex_to_str(unsigned int n, int use_upper)
{
	int		len;
	char	*str;

	len = get_hex_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	set_hexstr(n, use_upper, str);
	return (str);
}
