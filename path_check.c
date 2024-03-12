/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:16:02 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/05 18:15:39 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	scanforpath(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->x && j < game->y && game->mapcopy[i][j])
	{
		while (i < game->x && j < game->y && game->mapcopy[i][j])
		{
			if (game->mapcopy[i][j] == 'P' || game->mapcopy[i][j] == 'C'
				|| game->mapcopy[i][j] == 'E')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	flood_fill(t_game *game, int posx, int posy, char e)
{
	if ((posx < game->x && posy < game->y && posx > 0 && posy > 0)
		&& game->mapcopy[posx][posy] == e)
		return ;
	if (posx < game->x && posy < game->y && posx > 0 && posy > 0)
	{
		game->mapcopy[posx][posy] = e;
		flood_fill(game, posx + 1, posy, e);
		flood_fill(game, posx, posy + 1, e);
		flood_fill(game, posx - 1, posy, e);
		flood_fill(game, posx, posy - 1, e);
	}
}

int	path_check(t_game *game)
{
	flood_fill(game, game->posx, game->posy, '1');
	if (scanforpath(game) == 1)
		return (1);
	return (0);
}
