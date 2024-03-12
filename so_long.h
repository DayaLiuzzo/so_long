/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dliuzzo <dliuzzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:26:41 by dliuzzo           #+#    #+#             */
/*   Updated: 2024/02/06 17:55:09 by dliuzzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "mlx/mlx.h"
# include "libft/includes/libft.h"
# include "libft/includes/printf.h"
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_xmp
{
	void	*c;
	void	*e;
	void	*p;
	void	*w;
	void	*f;
	int		width;
	int		height;
}			t_xmp;

typedef struct s_game
{
	t_xmp	img;
	char	**map;
	char	**mapcopy;
	int		x;
	int		y;
	int		collect;
	int		copycollect;
	int		player;
	int		posy;
	int		posx;
	int		exity;
	int		exitx;
	int		exit;
	int		moves;
	int		complete;
	void	*mlxptr;
	void	*mlxwin;
}			t_game;

//Game
void		ft_move(t_game *game, int x, int y, int key);
int			checkmove(t_game *game, int x, int y, int key);
int			keyactions(int key, t_game *game);
// Rendering
int			displaygame(t_game *game);
void		img_init(t_game *game);
void		img_to_win(t_game *game, int x, int y);
// free
void		free_map(t_game *game);
void		free_mapcopy(t_game *game);
void		liberation(char *str, t_game *game);
void		liberation_win(t_game *game);
int			liberation2(char *str, t_game *game);
int			liberation3(t_game *game);
// PathFinding
void		flood_fill(t_game *game, int posx, int posy, char c);
int			path_check(t_game *game);
int			scanforpath(t_game *game);
// Map
char		*ft_strjoin2(char *s1, char *s2);
int			is_ber(char **av, int i, int j);
int			count_lines(char **av);
int			is_rectangle(t_game *game);
void		open_map(t_game *game, char **av, int ac);
void		copy_map(t_game *game);
void		game_init(t_game *game);
void		map_wallcheck(t_game *game);
void		map_elem_check(t_game *game);
void		map_char_check(t_game *game, char c, int x, int y);
void		resetpos(t_game *game);
// GNL
char		*get_line(char *storage);
char		*save_line(char *storage);
char		*line_reader(int fd, char *storage);
char		*get_next_line(int fd);
int			find_the_n(char *storage);
int			ft_strlen2(const char *str);
// EXEC
int			main(int ac, char **av);

#endif