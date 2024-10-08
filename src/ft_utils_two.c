#include "../includes/2D_game"

void	ft_good_message(t_data *p, char *str)
{
	p->ppl.moves++;
	ft_printf("Moves: %d\n", p->ppl.moves);
	ft_putendl_fd(str, 1);
	ft_putchar('\n');
	exit(EXIT_SUCCESS);
}

void	ft_protect_malloc(char *map)
{
	if (!map)
		free(map);
}

char	**ft_protect(char **mapp, char *temp)
{
	mapp = ft_split(temp, '\n');
	if (!mapp)
		ft_free(mapp, CLEAR "Free done");
	return (mapp);
}

void	ft_open_check(int file)
{
	if (file < 0)
	{
		close(file);
		exit(EXIT_FAILURE);
	}
}

void	ft_bad_message(t_data *p, char *str)
{
	p->ppl.moves++;
	ft_printf("Moves: %d\n", p->ppl.moves);
	ft_putendl_fd(str, 1);
	ft_putchar('\n');
	exit(EXIT_FAILURE);
}
