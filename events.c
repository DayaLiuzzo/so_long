/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:38:30 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/05 18:28:12 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkmove(t_game *game, int x, int y, int key)
{
	if (game->map[x][y] == '1')
		return (1);
	if (game->map[x][y] == 'C')
		game->collect--;
	if (x == game->exitx && y == game->exity && game->collect == 0)
	{
		game->complete = 1;
		ft_printf("Moves : %d\n", game->moves++);
		ft_printf("Bravoo ma Fillleee <3\n\n");
		liberation2("", game);
		return (0);
	}
	if (key != 'w' && key != 's' && key != 'a' && key != 'd' && key != XK_Left
		&& key != XK_Right && key != XK_Up && key != XK_Down)
		return (1);
	else
		return (0);
}

void	ft_move(t_game *game, int x, int y, int key)
{
	int	movecheck;
	int	col;
	int	row;

	col = game->posx;
	row = game->posy;
	movecheck = checkmove(game, x, y, key);
	if (movecheck != 1)
	{
		game->map[col][row] = '0';
		game->posx = x;
		game->posy = y;
		game->map[x][y] = 'P';
		ft_printf("Moves : %d\n", game->moves++);
	}
}

int	keyactions(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->posx;
	y = game->posy;
	if (key == 'w' || key == XK_Up)
		x--;
	else if (key == 's' || key == XK_Down)
		x++;
	else if (key == 'a' || key == XK_Left)
		y--;
	else if (key == 'd' || key == XK_Right)
		y++;
	else if (key == 65307)
		liberation_win(game);
	if (game->complete != 1)
		ft_move(game, x, y, key);
	return (0);
}

int	liberation3(t_game *game)
{
	if (game->map != NULL)
	{
		free_map(game);
		free_mapcopy(game);
	}
	if (game->mlxwin != NULL)
		mlx_destroy_window(game->mlxptr, game->mlxwin);
	if (game->img.c != NULL)
		mlx_destroy_image(game->mlxptr, game->img.c);
	if (game->img.p != NULL)
		mlx_destroy_image(game->mlxptr, game->img.p);
	if (game->img.e != NULL)
		mlx_destroy_image(game->mlxptr, game->img.e);
	if (game->img.w != NULL)
		mlx_destroy_image(game->mlxptr, game->img.w);
	if (game->img.f != NULL)
		mlx_destroy_image(game->mlxptr, game->img.f);
	if (game->mlxptr != NULL)
	{
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
	exit(0);
}
