/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:49:48 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/09 09:52:07 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	init_ptr(char *str)
{
	*str++ = '0';
	*str++ = 'x';
	return (2);
}

char	*pointer_to_str(void *pointer_like)
{
	int			len;
	char		*str;
	char		*temp;
	int			shift;
	uintptr_t	ptr;

	ptr = (uintptr_t)pointer_like;
	if (!ptr)
		return (ft_strdup("nil"));
	len = get_hex_len((unsigned int)ptr) + 3;
	str = ft_calloc(sizeof(char), len);
	if (!str)
		return (NULL);
	temp = str;
	temp += init_ptr(temp);
	shift = (sizeof(ptr) << 3) - 4;
	while (shift >= 0 && ((ptr >> shift) & 0xf) == 0)
		shift -= 4;
	while (shift >= 0)
	{
		*temp++ = (get_hex((ptr >> shift) & 0xf, 0));
		shift -= 4;
	}
	return (str);
}
