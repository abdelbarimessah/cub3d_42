/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:30:28 by amessah           #+#    #+#             */
/*   Updated: 2023/05/27 22:45:28 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_BONUS_H
# define RAYCASTING_BONUS_H

# define BUFFER_SIZE 1
# define EVENT_CLOSE 17
# define KEY_W 13
# define KEY_D 2
# define KEY_A 0
# define KEY_S 1
# define KEY_ESC 53
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define PI 3.141592
# define TILE_SIZE 32
# define FOV_ANGLE 60 
# define WALL_STRIP_WIDTH 1
# define MINI_MAP_SCALE 0.2
# define C2 0xC34A6A
# define C1 0x7AE2B3
# define WHITE 0xffffff
# define BLACK 0x000000
# define AQUA 0x00bda5
# define AQUA1 0x007667
# define GRAY 0x808080
# define GRAY1 0x302D2C
# define GRAY2 0xa4a4a5
# define BLUE 0x0000FF
# define RED 0xFF0000
# define WINDOW_HIGHT 960
# define WINDOW_WIDTH 1824

# include "../parse_bonus/parse_bonus.h"
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<string.h>
# include<unistd.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>

typedef struct s_line
{
	int		dx;
	int		dy;
	float	xinc;
	float	yinc;
	float	step;
	int		color;
	float	x;
	float	y;
}t_line;

typedef struct s_cast
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	float	nexthx;
	float	nexthy;
	float	nexthx_temp;
	float	nexthy_temp;
	float	nextvx;
	float	nextvy;
	float	nextvx_temp;
	float	nextvytemp;
	float	hdist;
	float	vdist;
	float	hitx;
	float	hity;
}t_cast;

typedef struct rays
{
	float	rayangle;
	float	distance;
	float	hitx;
	float	hity;
	int		facingup;
	int		facingdown;
	int		facingleft;
	int		facingright;
	int		foundhwh;
	int		foundvwh;
}t_rays;

typedef struct player
{
	float	raduis;
	float	turndirection;
	float	walkdirection;
	float	rotationangle;
	float	movespeed;
	float	rotationspeed;
	float	movestep;
	int		walk_a;
	int		walk_d;
	int		walk_s;
	int		walk_w;
}t_player;

typedef struct s_texture
{
	void	*image_ptr;
	int		*image_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		height;
	int		width;
	float	x;
	float	y;
}t_texture;

typedef struct s_render
{
	float	wallstripheight;
	float	ray_distance;
	float	distance_plane;
	int		i;
	int		wall_top_pix;
	int		wall_bot_pix;
	int		j;
	int		color;
	int		textureoffsetx;
	int		textureoffsety;
}t_render;

typedef struct map
{
	int			tile_size;
	void		*mlx;
	void		*win;
	void		*wall;
	void		*empty;
	void		*pl;
	int			img_h;
	int			img_w;
	float		px;
	float		py;
	char		**str;
	void		*img_ptr;
	int			*img_addr;
	int			bits_per_pixel;
	int			number_line;
	int			endian;
	void		*img_ptr_mini;
	int			*img_addr_mini;
	int			bits_per_pixel_mini;
	int			number_line_mini;
	int			endian_mini;
	int			count;
	int			maxlinelenght;
	int			num_rays;
	int			winw;
	int			winh;
	int			texture_nb;
	float		mini_map_scale;
	t_rays		*rays;
	t_player	player;
	t_maze		*maze;
	t_texture	*texture;
	t_render	render;
	t_line		line;
	t_cast		cast;
}t_map;

int		map_to_win(t_map *map);
void	mlx_initialization(t_map *map);
void	init_player_direction(t_map *map);
void	init_player_speed(t_map *map);
void	init_map_texture(t_map *map);
void	init_player_data(t_map *map);
void	initialize_img_data(t_map *map);
void	render_3d_walls(t_map *map);
void	render_ceil(t_map *map);
void	render_walls_floor(t_map *map);
void	number_texture(t_map *map, int i);
void	horizantal_intersection_calcul(t_map *map, t_rays ray);
void	horizantal_intersection_loop(t_map *map, t_rays *ray);
void	vertical_intersection_calcul(t_map *map, t_rays ray);
void	vertical_intersection_loop(t_map *map, t_rays *ray);
void	init_cast_variables(t_map *map);
int		create_rgb(int r, int g, int b);
float	distancebetwenpoint(float x1, float y1, float x2, float y2);
float	normlize(float rayngle);
void	cub3d_game(t_map *map);
void	get_player_position(t_map *map);
void	draw_line(t_map *map, float x2, float y2);
void	draw_map_rectangl(t_map *map, int i, int j);
void	cub3d_game(t_map *map);
void	init_player_data(t_map *map);
int		max_line_lenght(char **str);
void	render_circle(t_map *map, int x, int y, int r);
float	normlize(float rayngle);
float	distancebetwenpoint(float x1, float y1, float x2, float y2);
int		mouse_movement(int x, int y, void *param);
int		keyreleased(int key, void *param);
int		keypressed(int key, void *param);
void	update_player_place(t_map *map);
void	cast(t_map *map, t_rays ray, int position);
void	rays(t_map *map);
void	render_3d_walls(t_map *map);

#endif