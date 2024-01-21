/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:32:33 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/20 20:19:59 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	**parse_map_params(char *args, int **map_params, int map_size)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (*args)
	{
		if (*args == ' ')
		{
			args++;
			continue ;
		}
		if (i == map_size)
		{
			n++;
			i = 0;
		}
		map_params[n][i] = *args - '0';
		args++;
		i++;
	}
	return (map_params);
}

int	*row_top_params(int **map_params)
{
	return (map_params[0]);
}

int	*row_down_params(int **map_params)
{
	return (map_params[1]);
}

int	*row_left_params(int **map_params)
{
	return (map_params[2]);
}

int	*row_right_params(int **map_params)
{
	return (map_params[3]);
}
