/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:24:40 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/24 10:04:44 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = 0;
	while (1)
	{
		if (*s == (unsigned char)c)
			p = s;
		if (*s == '\0')
			return ((char *)p);
		s++;
	}
}
