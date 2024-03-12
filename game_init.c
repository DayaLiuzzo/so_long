/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:42:17 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/05 18:15:28 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->map = NULL;
	game->mapcopy = NULL;
	game->x = 0;
	game->y = 0;
	game->collect = 0;
	game->copycollect = 0;
	game->player = 0;
	game->posy = 0;
	game->posx = 0;
	game->exit = 0;
	game->moves = 0;
	game->complete = 0;
	game->mlxptr = mlx_init();
	if (!game->mlxptr)
		exit(1);
	game->mlxwin = NULL;
}

void	resetpos(t_game *game)
{
	game->posx = 0;
	game->posy = 0;
}

void	img_init(t_game *game)
{
	game->img.c = mlx_xpm_file_to_image(game->mlxptr, "textures/c.xpm",
			&game->img.width, &game->img.height);
	game->img.e = mlx_xpm_file_to_image(game->mlxptr, "textures/e.xpm",
			&game->img.width, &game->img.height);
	game->img.p = mlx_xpm_file_to_image(game->mlxptr, "textures/p.xpm",
			&game->img.width, &game->img.height);
	game->img.w = mlx_xpm_file_to_image(game->mlxptr, "textures/w.xpm",
			&game->img.width, &game->img.height);
	game->img.f = mlx_xpm_file_to_image(game->mlxptr, "textures/f.xpm",
			&game->img.width, &game->img.height);
	if (!game->img.c || !game->img.e || !game->img.p || !game->img.w
		|| !game->img.f)
		liberation2("TEXTURE ERROR\n", game);
}

void	img_to_win(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlxptr, game->mlxwin, game->img.c, y * 64,
			x * 64);
	else if (game->map[x][y] == 'P')
		mlx_put_image_to_window(game->mlxptr, game->mlxwin, game->img.p, y * 64,
			x * 64);
	else if (x == game->exitx && y == game->exity)
		mlx_put_image_to_window(game->mlxptr, game->mlxwin, game->img.e, y * 64,
			x * 64);
	else if (game->map[x][y] == '1')
		mlx_put_image_to_window(game->mlxptr, game->mlxwin, game->img.w, y * 64,
			x * 64);
	else if (game->map[x][y] == '0')
		mlx_put_image_to_window(game->mlxptr, game->mlxwin, game->img.f, y * 64,
			x * 64);
	if (!game->img.c || !game->img.e || !game->img.p || !game->img.w
		|| !game->img.f)
		liberation2("TEXTURE ERROR\n", game);
}

int	displaygame(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	if (game->mlxwin)
	{
		while (game->map[++x])
		{
			y = 0;
			while (game->map[x][y])
			{
				img_to_win(game, x, y);
				y++;
			}
		}
	}
	return (0);
}
