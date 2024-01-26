/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:22:31 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/23 09:52:34 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	row_is_ok(int *row, int row_index, int **map_params, int row_len);
int	col_is_ok(int **map, int index, int **map_params, int len);

int	*copy(int *arr, int size)
{
	int	i;
	int	*_copy;

	_copy = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		_copy[i] = arr[i];
		i++;
	}
	return (_copy);
}

int	verify_right(int *to_verify, int len, int constraint)
{
	int	i;
	int	right_count;
	int	max_height;

	right_count = 0;
	max_height = 0;
	i = len - 1;
	while (i >= 0)
	{
		if (to_verify[i] > max_height)
		{
			right_count++;
			max_height = to_verify[i];
		}
		i--;
	}
	return (right_count == constraint);
}

int	verify(int *to_verify, int len, int constraint[2])
{
	int	i;
	int	left_count;
	int	max_height;

	i = 0;
	left_count = 0;
	max_height = 0;
	while (i < len)
	{
		if (to_verify[i] > max_height)
		{
			left_count++;
			max_height = to_verify[i];
		}
		i++;
	}
	return (left_count == constraint[0] && verify_right(to_verify, len,
			constraint[1]));
}

int	solved(int **map, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] == 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	all_is_ok(int **map, int row, int col, int **map_params)
{
	if (!row_is_ok(map[row], row, map_params, 4))
		return (0);
	if (!col_is_ok(map, col, map_params, 4))
		return (0);
	if (!solved(map, 4))
		return (0);
	return (1);
}
