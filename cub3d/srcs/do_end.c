/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:46:35 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 15:31:16 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/cub3d.h"

void	do_error(int num, char **line, t_cub *base)
{
	int		idx;

	idx = 0;
	write(1, "ERROR\n", 6);
	if (num == 1)
		write(1, strerror(EINVAL), ft_strlen(strerror(EINVAL)));
	else if (num == 2 || num == 3)
		write(1, strerror(ENOENT), ft_strlen(strerror(ENOENT)));
	else if (num == 4)
		write(1, strerror(E2BIG), ft_strlen(strerror(E2BIG)));
	else if (num == 5)
		write(1, "Map argument is invalid", 23);
	else if (num == 6)
		write(1, "XPM File is damaged", 19);
	else if (num == 7)
	{
		write(1, "Map Error", 9);
		while (idx < base->maplen)
			free(base->worldmap[idx++]);
	}
	if (num >= 3 && num <= 6)
		free(*line);
	exit(-1);
}

int		exit_proc(void *param)
{
	int		idx;
	t_cub	*base;

	base = (t_cub*)param;
	idx = 0;
	while (idx < base->maplen)
		free(base->worldmap[idx++]);
	idx = 0;
	while (idx < 5)
		free(base->tex[idx++]);
	if (base->mode == 1)
		mlx_destroy_window(base->mlx, base->win);
	exit(0);
	return (0);
}
