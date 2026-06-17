/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:45:11 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/17 15:11:37 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

void	board_init(t_board *board, char **argv)
{	
	board->width = argv[1];
	board->height = argv[2];
	board->iteration = argv[3];
	board->board = calloc(board->width * board->height, sizeof(char));
	board->next = calloc(board->width * board->height, sizeof(char));
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		fprintf(stderr, "You must enter exactly 4 arguments");
	
	t_board	board;
	board_init(&board, argv);
	
	return (0);	
}
