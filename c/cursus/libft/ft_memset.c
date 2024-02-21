/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 05:58:43 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/20 05:58:44 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	int		i;
	char	*str;
	char	character;

	str = (char *)s;
	character = (unsigned char)c;
	while (i < n)
	{
		str[i] = character;
		i++;
	}
	return ((void *)str);
}
