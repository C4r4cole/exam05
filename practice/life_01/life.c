/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:45:11 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/22 15:13:11 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void print_map(t_game game)
{
	for (int y = 0; y < game.height; ++y)
	{
		for (int x = 0; x < game.width; ++x)
		{
			putchar(game.map[y][x]);
		}
		putchar('\n');
	}
}

void	free_map(t_game *game)
{
	if (game->map)
	{
		for (int i = 0; i < game->height; ++i)
		{
			if (game->map[i])
				free(game->map[i]);
		}
		free(game->map);
	}
}

void	init_game(t_game *game, char **argv)
{
	game->width = atoi(argv[1]);
	game->height = atoi(argv[2]);
	game->iteration = atoi(argv[3]);
	
	game->map = malloc(game->height * sizeof(char *));
	for (int y = 0; y < game->height; ++y)
	{
		game->map[y] = malloc(game->width * sizeof(char));
		for (int x = 0; x < game->width; ++x)
			game->map[y][x] = ' ';
	}
}

void	fill_map(t_game *game)
{
	char buffer;
	int	x = 0;
	int	y = 0;
	bool draw = false;
	while (read(STDIN_FILENO, &buffer, 1) == 1)
	{
		switch(buffer)
		{
			case ('w'):
				if (y > 0)
				{
					--y;
				}
				break ;
			case ('a'):
				if (x > 0)
				{
					--x;
				}
				break ;
			case ('s'):
				if (y < game->height - 1)
				{
					++y;
				}
				break ;
			case ('d'):
				if (x < game->height - 1)
				{
					++x;
				}
				break ;
			case ('x'):
				draw = !draw;
				break ;
			default: continue;
		}
		
		if (draw && x >= 0 && x <= game->width - 1 && y >= 0 && y <= game->height - 1)
			game->map[y][x] = 'O';
	}
}

int	count_neighbours(t_game *game, int y, int x)
{
	int	count = 0;
	
	for (int dy = -1; dy < 2; ++dy)
	{
		for (int dx = -1; dx < 2; ++dx)
		{
			if (dy == 0 && dx == 0)
				continue ;
			
			int nx = x + dx;
			int ny = y + dy;
			
			if (nx >= 0 && nx < game->width && ny >= 0 && ny < game->height && game->map[ny][nx] == '0')
				count++;
		}
	}
	return (count);
}

void	play_game(t_game *game)
{
	char **new_map = malloc(game->height * sizeof(char *));
	for (int y = 0; y < game->height; ++y)
	{
		new_map[y] = malloc(game->width * sizeof(char));
	}
	
	for (int y = 0; y < game->height; ++y)
	{
		for (int x = 0; x < game->width; ++x)
		{
			int neighbours = count_neighbours(game, y, x);
			if (game->map[y][x] == 'O')
			{
				if (neighbours == 2 || neighbours == 3)
					new_map[y][x] = 'O';
				else
					new_map[y][x] = ' ';
			}
			else
			{
				if (neighbours == 3)
					new_map[y][x] = 'O';
				else
					new_map[y][x] = ' ';
			}
		}
	}
	free_map(game);
	game->map = new_map;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	t_game	game;

	init_game(&game, argv);
	fill_map(&game);

	for (int i = 0; i < game.iteration; ++i)
		play_game(&game);
	
	print_map(game);
	free_map(&game);
	
	return (0);	
}
