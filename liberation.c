/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:29:22 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/05 18:26:20 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	v;

	v = 0;
	if (game->map)
	{
		while (game->map[v])
		{
			free(game->map[v]);
			v++;
		}
		free(game->map);
	}
}

void	free_mapcopy(t_game *game)
{
	int	v;

	v = 0;
	if (game->mapcopy)
	{
		while (game->mapcopy[v])
		{
			free(game->mapcopy[v]);
			v++;
		}
		free(game->mapcopy);
	}
}

void	liberation(char *str, t_game *game)
{
	if (game->map != NULL)
	{
		free_map(game);
		free_mapcopy(game);
	}
	if (game->mlxptr != NULL)
	{
		mlx_destroy_display(game->mlxptr);
		free(game->mlxptr);
	}
	if (str != NULL)
	{
		ft_printf("%s", str);
	}
	exit(0);
}

void	liberation_win(t_game *game)
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

int	liberation2(char *str, t_game *game)
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
	ft_printf("%s", str);
	exit(0);
}
