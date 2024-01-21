/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:22:43 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/21 00:31:32 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);

int	**init_map(int map_size)
{
	int	i;
	int	**map;

	i = 0;
	map = (int **)malloc(map_size * sizeof(int *));
	while (i < map_size)
	{
		map[i] = (int *)malloc(map_size * sizeof(int));
		i++;
	}
	return (map);
}

void	free_map(int **map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_map(int **map, int map_size)
{
	int		i;
	int		j;
	int		cell;
	int		*line;
	char	cell_as_char;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		line = map[i];
		while (j < map_size)
		{
			cell = line[j];
			cell_as_char = cell + '0';
			write(1, &cell_as_char, 1);
			if (j < map_size - 1)
			{
				ft_putstr(" ");
			}
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
