/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:09:30 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/05 18:10:07 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangle(t_game *game)
{
	int	tmpx;
	int	tmpy;

	tmpx = 0;
	tmpy = 0;
	while (game->map[tmpx][game->y] && game->map[tmpx][game->y] != '\n')
		game->y++;
	while (game->map[tmpx] && game->map[tmpx][tmpy])
	{
		while (game->map[tmpx][tmpy] && game->map[tmpx][tmpy] != '\n')
			tmpy++;
		if (tmpy != game->y)
			return (1);
		tmpx++;
		tmpy = 0;
	}
	return (0);
}

void	map_wallcheck(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->x)
	{
		j = 0;
		while (j < game->y)
		{
			if (game->map[0][j] != '1' || game->map[game->x - 1][j] != '1')
				liberation("Wall Missing\n", game);
			if (game->map[i][0] != '1' || game->map[i][game->y - 1] != '1')
				liberation("Wall Missing\n", game);
			j++;
		}
		i++;
	}
}

void	map_char_check(t_game *game, char c, int x, int y)
{
	if (c == 'C')
		game->collect++;
	else if (c == 'E')
	{
		game->exit++;
		game->exity = y;
		game->exitx = x;
	}
	else if (c == 'P')
	{
		game->player++;
		game->posy = y;
		game->posx = x;
	}
	else if (c == '1' || c == '0')
		return ;
	else
		liberation("Element error\n", game);
}

void	map_elem_check(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->x)
	{
		y = 0;
		while (y < game->y)
		{
			map_char_check(game, game->map[x][y], x, y);
			y++;
		}
		x++;
	}
	if (game->collect == 0)
		liberation("No Watermelon\n", game);
	if (game->player == 0)
		liberation("No Player\n", game);
	if (game->player > 1)
		liberation("Too many Players\n", game);
	if (game->exit == 0 || game->exit > 1)
		liberation("Exits issue\n", game);
}
