/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:29:56 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/21 06:47:27 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		all_is_ok(int **map, int row, int col, int **map_params);

void	print_map(int **map, int map_size);

int	is_safe(int **map, int row, int col, int n)
{
	int	i;
	int	map_size;

	i = 0;
	map_size = 4;
	while (i < map_size)
	{
		if (map[row][i] == n || map[i][col] == n)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	process_empty_cell(int **map, int **map_params, int coordinates[2],
		void (*callback)(int **, int **, int, int))
{
	int	temp;
	int	row;
	int	col;

	temp = 1;
	row = coordinates[0];
	col = coordinates[1];
	while (temp <= 4)
	{
		if (is_safe(map, row, col, temp))
		{
			map[row][col] = temp;
			callback(map, map_params, row, col);
			if (all_is_ok(map, row, col, map_params))
				return ;
			map[row][col] = 0;
		}
		temp++;
	}
}

void	iterate_cells(int **map, int **map_params, int coordinates[2],
		void (*callback)(int **, int **, int, int))
{
	while (coordinates[0] < 4)
	{
		while (coordinates[1] < 4)
		{
			if (map[coordinates[0]][coordinates[1]] == 0)
			{
				process_empty_cell(map, map_params, coordinates, callback);
				return ;
			}
			coordinates[1]++;
		}
		coordinates[1] = 0;
		coordinates[0]++;
	}
}

void	solve(int **map, int **map_params, int row, int col)
{
	int	coordinates[2];

	coordinates[0] = row;
	coordinates[1] = col;
	iterate_cells(map, map_params, coordinates, &solve);
}
