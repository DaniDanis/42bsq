/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadantas <dadantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:40 by lde-agui          #+#    #+#             */
/*   Updated: 2023/09/06 09:52:31 by dadantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdio.h>
#include <stdlib.h>

void	print_int_map(int **map, t_map *config)
{
	int line;
	int column;

	line = 0;
	column = 0;
	while (line < config->line_length)
    {
		column = 0;
        while (column < config->line_length)
        {
            printf("%i ", map[line][column]);
            column++;
        }
        line++;
        printf("\n");
    }
}

int **make_heat(char **map, t_map *config, int **heat_map)
{
    int line;
    int column;
    int max_depth;

    line = 0;
    column = 0;
    while (column < config->line_length)
    {
        max_depth = 0;
        line = config->line_length - 1;
        while (line >= 0)
        {
            if (map[line][column] == config->empty_character)
                max_depth++;
            else
                max_depth = 0;
            heat_map[line][column] = max_depth;
            line--;
        }
        column++;
    }
    return (heat_map);
}

t_map_square    *find_square(t_map *config, t_map_square *biggest_square, int **heat_map)
{
    // biggest_square->i = 1;
    // biggest_square->j = 0;
    // biggest_square->size = 0;
    // i = line
    // j = column
    int line;
    int column;
    int size;
    t_map_square aux;

    line = 0;
    size = 1;
    column = 0;
    if (heat_map && config)
        biggest_square->size = 0;
    aux.i = 0;
    aux.j = 0;
    aux.size = 0;
    return (biggest_square);
}

int	**create_heat_map(char **map, t_map *config)
{
    int **heat_map;
    int index;

    index = 0;
    heat_map = (int **)malloc(config->line_length * sizeof(int *));
    while (index < config->line_length)
    {
        heat_map[index] = (int *)malloc(config->line_length * sizeof(int));
        index++;
    }
    make_heat(map, config, heat_map);
    return (heat_map);
}
void	find_biggest_square(char **map, t_map *config)
{
    int **heat_map;
    t_map_square biggest_square;

    heat_map = create_heat_map(map, config);
    // Use the heat_map to find the biggest square
    find_square(config, &biggest_square, heat_map);
    
    // printf("\n%d\n%d\n%d\n", biggest_square.i, biggest_square.j, biggest_square.size);
    print_int_map(heat_map, config);
    free(heat_map);
}
