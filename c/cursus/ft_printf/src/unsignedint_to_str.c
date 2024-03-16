/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignedint_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:34:37 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/16 11:21:49 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_str(unsigned int n, char *dst)
{
	if (n >= 10)
	{
		set_str((n / 10), dst);
		dst += ft_strlen(dst);
		set_str((n % 10), dst);
	}
	else
		*dst = n + '0';
}

char	*unsigned_to_str(unsigned int n)
{
	int		len;
	char	*str;

	len = get_int_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	set_str(n, str);
	return (str);
}
