/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:16:14 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_position(t_cub *base, int idx, int idx2)
{
	base->posx = (double)idx;
	base->posy = (double)idx2;
}

void	preproc_map_du(int idx, int idx2, int mode, t_cub *base)
{
	if (mode == 0 || mode == 1)
	{
		base->diry = 0;
		base->planex = 0;
		base->dirx = 1.0;
		base->planey = 1.0;
		if (mode == 0)
			base->dirx *= -1;
		if (mode == 1)
			base->planey *= -1;
	}
	if (mode == 2 || mode == 3)
	{
		base->dirx = 0;
		base->planey = 0;
		base->diry = 1.0;
		base->planex = 1.0;
		if (mode == 3)
		{
			base->diry = -1.0;
			base->planex = -1.0;
		}
	}
	init_position(base, idx, idx2);
	base->worldmap[idx][idx2] = 0;
}

void	preproc_map(char **worldmap, t_cub *base)
{
	int		idx;
	size_t	len;
	size_t	idx2;

	idx = -1;
	while (++idx < base->maplen)
	{
		idx2 = 0;
		len = ft_strlen(worldmap[idx]);
		while (idx2 < len)
		{
			if (worldmap[idx][idx2] >= '0'
			&& worldmap[idx][idx2] <= '9')
				worldmap[idx][idx2] -= '0';
			if (worldmap[idx][idx2] == 'N')
				preproc_map_du(idx, idx2, 0, base);
			if (worldmap[idx][idx2] == 'S')
				preproc_map_du(idx, idx2, 1, base);
			if (worldmap[idx][idx2] == 'E')
				preproc_map_du(idx, idx2, 2, base);
			if (worldmap[idx][idx2] == 'W')
				preproc_map_du(idx, idx2, 3, base);
			idx2++;
		}
	}
}
