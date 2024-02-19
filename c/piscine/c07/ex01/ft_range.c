/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:05:32 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/27 10:53:40 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*range;

	i = 0;
	range = 0;
	size = max - min;
	if (size < 0)
		return ((void *)range);
	range = (int *)malloc(size * sizeof(int));
	while (i < size)
	{
		range[i] = min++;
		i++;
	}
	return (range);
}
