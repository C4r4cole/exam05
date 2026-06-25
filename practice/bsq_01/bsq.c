/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:17:35 by fmoulin           #+#    #+#             */
/*   Updated: 2026/06/23 15:53:07 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_file(char *filename)
{
	int		fd;
	char	buf[1024];
	char	*content = NULL;
	int		size = 0;
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return NULL;
	while ((ret = read(fd, &buf, 1024)) > 0)
	{
		
	}
}

int	main(int argc, char **argv)
{
	char	*file;
	t_map	map;
	int		pos;

	if (argc != 2)
		return (1);
	file = read_file(argv[1]);
	if (!file)
		return (1);
	if (!parse_header(file, &map, &pos) || !parse_map(file, &map, pos))
	{
		write(2, "map error\n", 10);
		free(file);
		return (1);
	}
	solve(&map);
	print_map(&map);
	free(map.data);
	free(file);	
	return (0);
}