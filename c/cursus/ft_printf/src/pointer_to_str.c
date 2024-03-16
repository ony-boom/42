/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:49:48 by rony-lov          #+#    #+#             */
/*   Updated: 2024/03/16 12:49:34 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pointer_to_str(void *pointer_like)
{
	int			i;
	char		str[32];
	int			shift;
	uintptr_t	ptr;

	i = 0;
	ptr = (uintptr_t)pointer_like;
	if (!ptr)
		return (ft_strdup("(nil)"));
	str[0] = '0';
	str[1] = 'x';
	i += 2;
	shift = (sizeof(ptr) << 3) - 4;
	while (shift >= 0 && ((ptr >> shift) & 0xf) == 0)
		shift -= 4;
	while (shift >= 0)
	{
		str[i++] = (get_hex((ptr >> shift) & 0xf, 0));
		shift -= 4;
	}
	str[i] = '\0';
	return (ft_strdup(str));
}
