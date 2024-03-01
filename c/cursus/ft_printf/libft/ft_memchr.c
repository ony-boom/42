/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:39:02 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/24 15:48:27 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	unsigned char	*src;

	src = (unsigned char *)s;
	while (n)
	{
		if (*src == (unsigned char)c)
			return (src);
		src++;
		n--;
	}
	return (0);
}
