/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:46:35 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 15:30:58 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/cub3d.h"

void	map_check_dup(char **worldmap, t_cub *base)
{
	int	idx;
	int	idx2;

	idx = 0;
	while (idx < base->maplen)
	{
		idx2 = 0;
		while (worldmap[idx][idx2])
		{
			if (worldmap[idx][idx2] != ' ' && worldmap[idx][idx2] != '0'
			&& worldmap[idx][idx2] != '1' && worldmap[idx][idx2] != '2'
			&& worldmap[idx][idx2] != 'N' && worldmap[idx][idx2] != 'S'
			&& worldmap[idx][idx2] != 'E' && worldmap[idx][idx2] != 'W'
			&& worldmap[idx][idx2] != 0)
				do_error(7, 0, base);
			if (worldmap[idx][idx2] == 'N' || worldmap[idx][idx2] == 'S'
			|| worldmap[idx][idx2] == 'E' || worldmap[idx][idx2] == 'W')
			{
				base->dirword = worldmap[idx][idx2];
				(base->check)++;
			}
			idx2++;
		}
		idx++;
	}
}

void	map_check_x(char **worldmap, t_cub *base)
{
	int	idx;
	int	idx2;

	idx = -1;
	while (++idx < base->maplen)
	{
		idx2 = 1;
		if (worldmap[idx][0] != '1' && worldmap[idx][0] != ' ')
			do_error(7, 0, base);
		while (worldmap[idx][idx2 + 1])
		{
			if (idx == 0 || idx == base->maplen - 1)
			{
				if (worldmap[idx][idx2] != '1' && worldmap[idx][idx2] != ' ')
					do_error(7, 0, base);
			}
			if ((worldmap[idx][idx2] == '0'
			|| worldmap[idx][idx2] == base->dirword)
			&& (worldmap[idx][idx2 - 1] == ' '
			|| worldmap[idx][idx2 + 1] == ' '
			|| worldmap[idx][idx2 + 1] == 0))
				do_error(7, 0, base);
			idx2++;
		}
	}
}

void	map_check_y(char **worldmap, t_cub *base)
{
	int	idx;
	int	idx2;

	idx = 0;
	idx2 = 0;
	while (worldmap[idx][idx2])
	{
		idx = 1;
		if (worldmap[0][idx2] != '1' && worldmap[0][idx2] != ' ')
			do_error(7, 0, base);
		if (worldmap[base->maplen - 1][idx2] != '1'
		&& worldmap[base->maplen - 1][idx2] != ' ')
			do_error(7, 0, base);
		while (idx < base->maplen - 2)
		{
			if ((worldmap[idx][idx2] == '0'
			|| worldmap[idx][idx2] == base->dirword)
			&& (worldmap[idx - 1][idx2] == ' '
			|| worldmap[idx + 1][idx2] == ' '))
				do_error(7, 0, base);
			idx++;
		}
		idx2++;
	}
}

void	map_check(char **worldmap, t_cub *base)
{
	map_check_dup(worldmap, base);
	if (base->check > 1)
		do_error(7, 0, base);
	map_check_x(worldmap, base);
	map_check_y(worldmap, base);
}
