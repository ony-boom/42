/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:07:35 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/26 07:20:20 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
	str = ft_calloc(len, sizeof(int));

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

static int	get_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
