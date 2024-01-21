/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:51:50 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/21 00:35:37 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
int		*row_left_params(int **map_params);
int		*row_right_params(int **map_params);
int		verify(int *to_verify, int len, int constraint[2]);

int	row_is_ok(int *row, int row_index, int **map_params, int row_len)
{
	int	constraint[2];
	int	is_ok;

	constraint[0] = row_left_params(map_params)[row_index];
	constraint[1] = row_right_params(map_params)[row_index];
	is_ok = verify(row, row_len, constraint);
	return (is_ok);
}
