/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:26:17 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/05 18:24:09 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	game_init(&game);
	open_map(&game, av, ac);
	map_wallcheck(&game);
	map_elem_check(&game);
	if (path_check(&game) == 1)
	{
		game.mlxwin = mlx_new_window(game.mlxptr, game.y * 64, game.x * 64,
				"Peach story");
		img_init(&game);
		mlx_loop_hook(game.mlxptr, displaygame, &game);
		mlx_hook(game.mlxwin, 2, 1L << 0, keyactions, &game);
		mlx_hook(game.mlxwin, 33, 0l, liberation3, &game);
		mlx_loop(game.mlxptr);
	}
	liberation("", &game);
}
