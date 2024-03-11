/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:29:17 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/09 23:53:51 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *base_str)
{
	int		num;
	char	*str;
	int		str_n;
	int		is_negative;

	num = 0;
	str = trim_start((char *)base_str);
	str_n = 0;
	is_negative = *str == '-';
	if (*str == '-' || *str == '+')
		str++;
	if (!*str || !ft_isnum(*str, &str_n))
		return (0);
	num = *str - '0';
	str++;
	while (ft_isnum(*str, &str_n))
	{
		num *= 10;
		num += str_n;
		str++;
	}
	if (is_negative)
		num *= -1;
	return (num);
}
