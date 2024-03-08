/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:07:35 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/26 13:41:29 by username         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long n);

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;
	long	number;

	number = ft_abs(n);
	len = get_len(n) + 1;
	i = len - 2;
	str = ft_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	while (i >= 0)
	{
		str[i] = (number % 10) + '0';
		number /= 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

// Don't ever judge this code, it is fast than loop
// It's ugly I admit it, yet It's fast
static int	get_len(long x)
{
	if (x < 0)
		return (get_len(-x) + 1);
	if (x >= 1000000000)
		return (10);
	if (x >= 100000000)
		return (9);
	if (x >= 10000000)
		return (8);
	if (x >= 1000000)
		return (7);
	if (x >= 100000)
		return (6);
	if (x >= 10000)
		return (5);
	if (x >= 1000)
		return (4);
	if (x >= 100)
		return (3);
	if (x >= 10)
		return (2);
	return (1);
}