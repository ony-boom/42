/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cols.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:30:38 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/21 00:29:11 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*row_top_params(int **map_params);
int	*row_down_params(int **map_params);
int	verify(int *to_verify, int len, int constraint[2]);

int	*make_cols(int **map, int index, int size)
{
	int	i;
	int	j;
	int	*cols;

	cols = (int *)malloc(size * sizeof(int));
	i = 0;
	j = 0;
	while (i < size)
	{
		cols[i] = map[i][index];
		i++;
	}
	return (cols);
}

int	col_is_ok(int **map, int index, int **map_params, int len)
{
	int	*cols;
	int	constraint[2];
	int	is_ok;

	cols = make_cols(map, index, len);
	constraint[0] = row_top_params(map_params)[index];
	constraint[1] = row_down_params(map_params)[index];
	is_ok = verify(cols, len, constraint);
	free(cols);
	return (is_ok);
}
