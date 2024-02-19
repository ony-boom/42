/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:41:18 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/27 10:52:49 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*make_range(int min, int max, int *r_size)
{
	int	i;
	int	size;
	int	*range;

	i = 0;
	range = 0;
	size = max - min;
	if (size < 0)
	{
		*r_size = size;
		return ((void *)range);
	}
	range = (int *)malloc(size * sizeof(int));
	if (range == NULL)
	{
		*r_size = -1;
		return ((void *)range);
	}
	while (i < size)
	{
		range[i] = min++;
		i++;
	}
	*r_size = size;
	return (range);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*r;
	int	size;

	size = 0;
	r = make_range(min, max, &size);
	*range = r;
	return (size);
}
