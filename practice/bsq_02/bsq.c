/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:30:19 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/25 15:46:16 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	parse_header(char *line, t_map *map)
{
	int	len = strlen(line);
	int i = 0;
	int nb = 0;
	
	map->full = line[len - 1];
	map->obstacle = line[len - 2];
	map->empty = line[len - 3];

	if (len < 5 || line[len - 1] != '\n')
		return (0);
	if (!is_printable(map->full) || !is_printable(map->empty) || !is_printable(map->obstacle))
		return (0);
	if (map->full == map->obstacle || map->obstacle == map->empty || map->empty == map->full)
		return (0);
	while (i < len - 4)
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		nb = nb * 10 + line[i] - '0';
		i++;
	}
	if (nb <= 0)
		return (0);
	map->height = nb;
	return (1);
}

int read_map(FILE *file, t_map *map)
{
	char	*line = NULL;
	size_t	cap = 0;
	int 	y = 0;
	int 	len;

	map->grid = calloc(map->height, sizeof(char *));
	if (!map->grid)
		return (0);
	while (y < map->height && getline(&line, &cap, file) != -1)
	{
		len = strlen(line);
		if (len < 2 || line[len - 1] != '\n')
			return (free(line), 0);
		line[len - 1] = '\0';
		if (y == 0)
			map->width = strlen(line);
		for (int x = 0; x < map->width; ++x)
		{
			if (line[x] != map->empty || line[x] != map->obstacle)
				return (free(line), 0);
		}
		map->grid[y] = strdup(line);
		if (!map->grid[y])
			return (free(line), 0);
		y++;
	}
	free(line);
	return (y == map->height);
}

t_best	solve_bsq(t_map *map)
{
	int		**dp;
	t_best	best = {0, 0, 0};

	dp = calloc(map->height, sizeof(int *));
	for (int y = 0; y < map->height; ++y)
		dp[y] = calloc(map->width, sizeof(int));

	for (int y = 0; y < map->height; ++y)
	{
		for (int x = 0; x < map->width; ++x)
		{
			if (map->grid[y][x] == map->obstacle)
				dp[y][x] = 0;
			else if (y == 0 || x == 0)
				dp[y][x] = 1;
			else
				dp[y][x] = 1 + min3(dp[y - 1][x], dp[y][x - 1], dp[y - 1][x - 1]);
			if (dp[y][x] > best.size)
			{
				best.size = dp[y][x];
				best.x = x;
				best.y = y;
			}
		}
	}
	for (int y = 0; y < map->height; ++y)
	{
		free(dp[y]);
	}
	free(dp);
	return (best);
}

int	process_file(FILE *file)
{
	t_map	map;
	char 	*header = NULL;
	size_t	cap = 0;
	t_best	best;

	if (getline(&header, &cap, file) == -1 || !parse_header(header, &map))
		return (free(header), 0);
	free(header);
	if (!read_map(file, &map))
		return(free_map(&map), 0);
	best = solve_bsq(&map);
	apply_square(&map, best);
	print_map(&map);
	free_map(&map);
	return(1);
}

int main(int argc, char **argv)
{
	FILE	*file;
	
	if (argc == 1)
	{
		if (!process_file(stdin))
			fprintf(stderr, "map error \n");
	}
	for (int i = 1; i < argc; i++)
	{
		file = fopen(argv[i], "r");
		if (!file || !process_file(file))
			fprintf(stderr, "map error \n");
		if (file)
			fclose(file);
		if (i < argc - 1)
			fputs("\n", stdout);
	}
	return (0);
}