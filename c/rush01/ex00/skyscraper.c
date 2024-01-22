/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rony-lov <rony-lov@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 08:55:36 by rony-lov          #+#    #+#             */
/*   Updated: 2024/01/21 15:54:43 by rony-lov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void solve(int **map, int **map_params, int row, int col);
int **rejet_map(int **map);
int **init_map(int map_size);
void free_map(int **map, int map_size);
void print_map(int **map, int map_size);
int **parse_map_params(char *args, int **map_params, int map_size);

int main(int argc, char *argv[]) {
  int **map;
  int **map_params;
  const int map_size = 4;
  int row;
  int col;

  row = 0;
  col = 0;
  if (argc < 2) {
    return (0);
  }
  map = init_map(map_size);
  map_params = init_map(map_size);
  parse_map_params(argv[1], map_params, map_size);
  rejet_map(map);
  solve(map, map_params, row, col);
  print_map(map, map_size);
  free_map(map, map_size);
  free_map(map_params, map_size);
}
