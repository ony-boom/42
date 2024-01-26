/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:05:32 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/24 09:15:21 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	c;
	int	size;
	int	*range;

	i = 0;
	c = min;
	range = 0;
	size = max - min;
	if (size < 0)
		return ((void *)range);
	range = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		range[i] = c;
		c++;
		i++;
	}
	return (range);
}
