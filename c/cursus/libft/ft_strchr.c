/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 06:22:10 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/21 16:04:18 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = (char *)s;
	if (c == '\0')
		return (char *)s + ft_strlen(s);
	while (*src)
	{
		if (*src == c)
			return (src);
		src++;
	}
	return (0);
}
