/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:50:08 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/27 22:44:11 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
// # include <mlx.h>

typedef struct s_player
{
	int	px;
	int	py;
	int	player_direction;
}				t_playre;

typedef struct s_maze
{
	struct s_player		player;
	char				**map;
	char				**map_checked;
	char				*north_path;
	char				*south_path;
	char				*west_path;
	char				*east_path;
	int					floor_color[3];
	int					ceiling_color[3];
	int					start_map_index;
	int					map_width;
	int					map_height;
	int					map_lenght;
	int					lock_c;
	int					lock_f;
	int					player_count;
	int					i;
	int					j;
	int					k;
}t_maze;

void	initialize_data(t_maze *data);
int		ft_strlen(char *str);
void	ft_error(char *status);
void	ft_putstr(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
char	*get_next_line(int fd);
int		ft_atoi(const char *str);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	map_check(t_maze *data, int ac, char **av);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strrchr(const char *s, int c);
int		is_wall(char *line, int flag);
void	is_only_wall(char *line, int *i, int flag);

void	north_traitement(t_maze *data, char *path, int *flag, int start);
void	south_traitement(t_maze *data, char *path, int *flag, int start);
void	east_traitement(t_maze *data, char *path, int *flag, int start);
void	west_traitement(t_maze *data, char *path, int *flag, int start);
void	directions_traitement(t_maze *data, char *path, int *flag, int start);
void	floor_ceiling_traitement(t_maze *data, char *path, \
	int *flag, int start);
void	fill_floor_ceiling(t_maze *data, char *color, char f_or_c, int *flag);

void	aux_directions_traitement(t_maze *data, char *path, \
	int *flag, int start);

int		is_space(char c, int flag);
void	check_space_surrounding(char **map, int i, int j);
void	store_map(char **map, t_maze *data);
void	map_treatment(t_maze *data, char **map, int i);

void	check_line_diff(char **map, int i, int len1, int len2);
void	check_n_fill_rgb(int *color, char *rgb, int index, int *flag);
void	check_rgb(char *rgb);
void	check_rgb_validation(char *rgb, int *count);
void	check_rgb(char *rgb);
int		rgb_len(char *rgb);
void	rgb_valide_num(char *rgb, int *i);

int		get_map_len(char **map, int i);
int		player_direction(t_maze *data,	char c);
void	map_is_valid(char **map, int start);
int		is_not_item(char c, t_maze *data);

void	trimming_endofmap(char **map);
int		custom_space(char **map, int i);
void	check_map_items(t_maze *data, char **map, int i);

char	**ft_split(char const *s, char c);

#endif