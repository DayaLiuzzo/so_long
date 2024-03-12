/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:13:20 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/05 18:18:25 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (game->x < 3)
		liberation("Map Too Small\n", game);
	game->mapcopy = ft_calloc((game->x + 1), sizeof(char *));
	while (i != game->x)
	{
		game->mapcopy[i] = ft_strdup(game->map[i]);
		i++;
	}
}

int	count_lines(char **av)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file\n");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	create_map(t_game *game, char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		liberation("File Error\n", game);
	game->x = count_lines(av);
	if (game->x < 3 || game->x > 20 || game->y > 34)
		liberation("Invalid Map Size\n", game);
	game->map = ft_calloc((game->x + 1), sizeof(char *));
	if (!game->map)
		liberation("Map mem Error\n", game);
	while (i != game->x)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[game->posx] = ft_strjoin2(game->map[game->posx], line);
		game->posx++;
		i++;
		free(line);
	}
	close(fd);
}

int	is_ber(char **av, int i, int j)
{
	int		end;
	char	*ber;

	ber = ".ber";
	i = 0;
	j = 0;
	end = -1;
	while (av[1][i])
	{
		if (av[1][i] == '.')
		{
			while (ber[j] && av[1][i])
			{
				if (ber[j] != av[1][i + j])
					return (1);
				j++;
				end = i + j;
			}
		}
		i++;
	}
	if (end != i)
		return (1);
	return (0);
}

void	open_map(t_game *game, char **av, int ac)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		if (is_ber(av, 0, 0) == 1)
			liberation("Wrong File Name\n", game);
		create_map(game, av);
		if (game->map == NULL)
			liberation("Map mem Error\n", game);
		if (is_rectangle(game) == 1)
			liberation("Isn't Rectangle\n", game);
		copy_map(game);
		if (game->mapcopy == NULL)
			liberation("Map mem Error\n", game);
		resetpos(game);
	}
}
