/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:46:35 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 15:31:00 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/cub3d.h"

int		check_error_input(int argc, char **argv)
{
	int	mode;

	mode = -1;
	if (argc == 2 &&
	!(ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 10)))
		mode = 1;
	else if (argc == 3 && !(ft_strncmp(argv[2], "--save", 10)))
		mode = 2;
	else
		do_error(1, 0, 0);
	return (mode);
}

void	run_mlx(t_cub *base)
{
	mlx_key_hook(base->win, do_key, base);
	mlx_hook(base->win, 17, 0, exit_proc, base);
	mlx_loop_hook(base->mlx, render_main, base);
	mlx_loop(base->mlx);
}

int		main(int argc, char *argv[])
{
	t_cub	base;

	base.check = 0;
	base.mode = check_error_input(argc, argv);
	base.mlx = mlx_init();
	base.maplen = parse_main(argv[1], &base);
	map_check(base.worldmap, &base);
	preproc_map(base.worldmap, &base);
	if (base.mode == 1)
	{
		base.win = mlx_new_window(base.mlx, base.w, base.h, "test");
		run_mlx(&base);
	}
	else
	{
		render_main(&base);
		exit_proc(&base);
	}
	return (0);
}
