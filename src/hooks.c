#include "../includes/2D_game.h"

int	key_hook(int keycode, t_data *mapp)
{
	if (keycode == KEY_UP || keycode == KEY_W)
		ft_up_move(mapp);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_down_move(mapp);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_left_move(mapp);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_right_move(mapp);
	if (keycode == KEY_ESC)
	{
		ft_printf(RED "Mission Failed\n");
		mlx_destroy_window(mapp->mlx, mapp->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	x_pressed(t_data *mapp)
{
	ft_printf(RED "Mission Failed\n");
	mlx_destroy_window(mapp->mlx, mapp->win);
	exit(EXIT_SUCCESS);
}
