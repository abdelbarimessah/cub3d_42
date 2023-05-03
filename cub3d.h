/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:30:28 by amessah           #+#    #+#             */
/*   Updated: 2023/04/28 10:22:32 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 1

# define EVENT_CLOSE 17
# define KEY_W 13
# define KEY_D 2
# define KEY_A 0
# define KEY_S 1
# define KEY_ESC 53
# define KEY_RIGHT 124
# define KEY_LEFT 123
#define PI 3.141592
# define C2 0xC34A6A
# define C1 0x7AE2B3
# define WHITE 0xffffff
# define BLACK 0x000000
# define AQUA 0x00bda5
# define AQUA1 0x007667
# define GRAY 0x808080
# define GRAY1 0x302D2C
# define GRAY2 0xa4a4a5

# define WALL "./image/wall.xpm"
# define EMPTY "./image/empty.xpm"
# define PLAYER "./image/player.xpm"

# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<string.h>
# include<unistd.h>
# include<mlx.h>
#include <math.h>

// map->bits_per_pixel, map->size_line, map->endian
typedef struct map
{
	char	**str;
	int		img_h;
	int		img_w;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*empty;
	void	*player;
	int 	px;
	int		py;
	int		pdx;
	int		pdy;
	int pa;
	int	pb;
	double	var;
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int 	number_line;
	int		endian;
	int	*img_addr;
}t_map;


// libft_outils
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **tab);
// map_read
int		check_file_name(char *str);
char	**map_read(int fd);
char	*reader(int fd);
void    cub3d_game(t_map *map);
int    map_to_win(t_map *map);
int		mouvement(int key, void *param);
int		position_j(char **str);
int		position_i(char **str);
void	draw_player(t_map *map);
void	draw_player1(t_map *map);
int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
void print_rectangl_for_player(t_map *conf, int y, int x, int color);
void	my_mlx_pixel_put(t_map *data, int x, int y, int color);

#endif