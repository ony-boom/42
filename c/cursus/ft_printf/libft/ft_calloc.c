/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:48:54 by rony-lov          #+#    #+#             */
/*   Updated: 2024/02/24 11:58:55 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nitems, int size)
{
	int				i;
	unsigned char	*mem;

	mem = malloc(nitems * size);
	i = 0;
	if (mem)
	{
		while (i < nitems * size)
		{
			mem[i] = 0;
			i++;
		}
	}
	return (mem);
}
