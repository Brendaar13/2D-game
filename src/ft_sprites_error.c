#include "../includes/2D_game"

void	ft_error_sprite(void *sprite, char *str)
{
	if (!sprite)
	{
		ft_printf("%s\n", str);
		exit(EXIT_FAILURE);
	}
}