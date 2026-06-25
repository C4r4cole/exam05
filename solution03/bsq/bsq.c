#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_map
{
	char	*data;
	int		width;
	int		height;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

typedef struct s_best
{
	int	size;
	int	x;
	int	y;
}	t_best;

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

int	min3(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return min;
}

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
	while ((ret = read(fd, buf, 1024)) > 0)
	{
		char *new_content = malloc(size + ret + 1);
		if (!new_content)
			return NULL;
		for (int i = 0; i < size; i++)
			new_content[i] = content[i];
		for (int i = 0; i < ret; i++)
			new_content[size + i] = buf[i];
		size += ret;
		new_content[size] = '\0';
		free(content);
		content = new_content;
	}
	close(fd);
	return content;
}

int	parse_header(char *file, t_map *map, int *pos)
{
	int i = 0;
	int nb = 0;

	while (file[i] >= '0' && file[i] <= '9')
	{
		nb = nb * 10 + file[i] - '0';
		i++;
	}
	if (nb <= 0 || !file[i] || !file[i + 1] || !file[i + 2])
		return 0;
	map->height = nb;
	map->empty = file[i];
	map->obstacle = file[i + 1];
	map->full = file[i + 2];
	if (file[i + 3] != '\n')
		return 0;
	*pos = i + 4;
	return 1;
}

int	parse_map(char *file, t_map *map, int pos)
{
	int start = pos;
	int width = 0;

	while (file[pos + width] && file[pos + width] != '\n')
		width++;
	if (width <= 0)
		return 0;
	map->width = width;
	map->data = malloc(map->width * map->height);
	if (!map->data)
		return 0;

	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			char c = file[start++];
			if (c != map->empty && c != map->obstacle)
				return 0;
			map->data[y * map->width + x] = c;
		}
		if (file[start] != '\n')
			return 0;
		start++;
	}
	return 1;
}

void	solve(t_map *map)
{
	int		*dp = malloc(sizeof(int) * map->width * map->height);
	t_best	best = {0, 0, 0};

	for (int y = 0; y < map->height; y++)
	{
		for (int x = 0; x < map->width; x++)
		{
			int i = y * map->width + x;
			if (map->data[i] == map->obstacle)
				dp[i] = 0;
			else if (x == 0 || y == 0)
				dp[i] = 1;
			else
			{
				int up = dp[(y - 1) * map->width + x];
				int left = dp[y * map->width + x - 1];
				int diag = dp[(y - 1) * map->width + x - 1];
				dp[i] = 1 + min3(up, left, diag);
			}
			if (dp[i] > best.size)
			{
				best.size = dp[i];
				best.x = x;
				best.y = y;
			}
		}
	}

	for (int y = best.y - best.size + 1; y <= best.y; y++)
		for (int x = best.x - best.size + 1; x <= best.x; x++)
			map->data[y * map->width + x] = map->full;

	free(dp);
}

void	print_map(t_map *map)
{
	for (int y = 0; y < map->height; y++)
	{
		write(1, map->data + y * map->width, map->width);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	char	*file;
	t_map	map;
	int		pos;

	if (argc != 2)
		return 1;
	file = read_file(argv[1]);
	if (!file)
		return 1;
	if (!parse_header(file, &map, &pos) || !parse_map(file, &map, pos))
	{
		write(2, "map error\n", 10);
		free(file);
		return 1;
	}
	solve(&map);
	print_map(&map);
	free(map.data);
	free(file);
	return 0;
}