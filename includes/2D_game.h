#ifndef 2D_game_H
# define 2D_game_H

# include "../MLX/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

# define CLEAR "\x1b[0m"
# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"

// Map size
typedef struct s_map
{
	int		row;
	int		line;
	int		fd;
}			t_map;

// Map content
typedef struct s_mapcnt
{
	int	player;
	int	coin;
	int	exit;
	int	coin_left;
	int	enemy;
	int	exit_count;
}		t_mapcnt;

// All player movements, including how many moves
// have we done.
typedef struct s_ppl
{
	int	moves;
	int	py;
	int	px;
	int	ey;
	int	ex;
	int	dir;
}		t_ppl;

// All paths
typedef struct s_img
{
	void	*cjright;
	void	*cjleft;
	void	*cj1right;
	void	*cj1left;
	void	*cj2r;
	void	*cj2l;
	void	*cjjump;
	void	*cjcrouch;
	void	*cjwait;
	void	*cjdown;
	void	*coin;
	void	*exit;
	void	*wall;
	void	*background;
	void	*policel;
	void	*policer;
	int		width;
	int		height;
}			t_img;

// All data required, include map and mapcontent
typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map_ref;
	char		**map_cpy;
	int			frame;
	int			frame_police;
	t_map		map;
	t_mapcnt	mapcnt;
	t_ppl		ppl;
	t_img		*img;
}				t_data;

// All Keycodes
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_CLOSE_WIN 17

//All functions needed
void	ft_free(char **map, char *str);
void	print_error(char *str);
void	ft_error(t_data *mlx);
int		get_num_rows(int fd);
size_t	max_len(char *s1, char *s2);
void	map_rectangle(char **map, int width, int height);
void	map_content(t_data *mapp);
void	map_chr_check(t_data *mapp);
void	map_saver(char **argv, t_data *mapp);
void	map_check(t_data *mapp);
void	ft_coin_left(t_data *mapp);
void	floodfill_map_coin(t_data *mapp, int y, int x);
void	valid_exit(t_data *mapp, int y, int x);
void	map_print(t_data *mapp);
t_map	map_maker(char **argv, t_data *mapp);
void	ft_left_move(t_data *P);
void	ft_up_move(t_data *P);
void	ft_down_move(t_data *P);
void	ft_right_move(t_data *P);
t_img	*image_put(t_data *mapp);
void	which_image(t_data *mapp, int i, int j);
int		random_num(void);
void	img_to_window(t_data *mapp);
void	fill_bckgnd(t_data *mapp);
void	find_p(t_data *mapp);
int		key_hook(int keycode, t_data *mapp);
int		x_pressed(t_data *mapp);
void	ft_put_img(t_data *map, int y, int x, void *file);
void	ft_moves(t_data *p, int y, int x);
bool	ft_is_readable(char *file);
void	ft_protect_malloc(char *map);
char	**ft_protect(char **mapp, char *temp);
void	ft_bad_message(t_data *p, char *str);
void	ft_good_message(t_data *p, char *str);
void	ft_error_sprite(void *sprite, char *str);

// All Bonus Functions

void	floodfill_map_coin_bonus(t_data *mapp, int y, int x);
void	map_content_bonus(t_data *mapp);
void	map_chr_check_bonus(t_data *mapp);
void	ft_left_move_bonus(t_data *p);
void	ft_up_move_bonus(t_data *p);
void	ft_down_move_bonus(t_data *p);
void	ft_right_move_bonus(t_data *p);
void	moves_counter_img(t_data *mapp);
void	img_to_window_bonus(t_data *mapp);
t_img	*player_sprites(t_data *mapp);
int		ft_frames(t_data *map);
int		ft_frames_police(t_data *map);
void	ft_player(t_data *p, int y, int x);
void	ft_stay_frame(t_data *p, int y, int x);
void	ft_right_frame(t_data *p, int y, int x);
void	ft_up_frame(t_data *p, int y, int x);
void	ft_down_frame(t_data *p, int y, int x);
void	ft_left_frame(t_data *p, int y, int x);
void	police_moves(t_data *p, int y, int x);
t_img	*player_sprites1(t_data *mapp);
t_img	*map_sprites(t_data *mapp);

#endif
