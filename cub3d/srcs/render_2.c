/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:46:35 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 15:30:39 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/cub3d.h"

void	select_tex(t_cub *base, t_ren *info)
{
	if (info->side == 0)
		info->wallx = base->posy + info->perpwalldist * info->raydiry;
	else
		info->wallx = base->posx + info->perpwalldist * info->raydirx;
	info->wallx -= floor(info->wallx);
	if (base->worldmap[info->mapx][info->mapy] == 1)
	{
		if (info->mapx - base->posx < 0 && info->side == 0)
			info->texnum = 0;
		else if (info->mapy - base->posy > 0 && info->side == 1)
			info->texnum = 2;
		else if (info->mapy - base->posy < 0 && info->side == 1)
			info->texnum = 3;
		else if (info->mapx - base->posx > 0 && info->side == 0)
			info->texnum = 1;
	}
	else if (base->worldmap[info->mapx][info->mapy] == 2)
		info->texnum = 4;
	info->texx = (int)(info->wallx * (double)base->twidth[info->texnum]);
	if (info->side == 0 && info->raydirx > 0)
		info->texx = base->twidth[info->texnum] - 1 - info->texx;
	if (info->side == 1 && info->raydiry < 0)
		info->texx = base->twidth[info->texnum] - 1 - info->texx;
}

void	put_base_color(t_cub *base, uint32_t *data)
{
	int	hei;
	int	wei;

	hei = 0;
	while (hei < (base->h) / 2 - 1)
	{
		wei = 0;
		while (wei < (base->w))
		{
			data[hei * (base->w) + wei] = base->f_color;
			wei++;
		}
		hei++;
	}
	while (hei < (base->h) - 1)
	{
		wei = 0;
		while (wei < (base->w))
		{
			data[hei * (base->w) + wei] = base->c_color;
			wei++;
		}
		hei++;
	}
}

void	put_pixel(int x, t_cub *base, t_ren *info, uint32_t *data)
{
	int			d;
	int			texy;
	uint32_t	color;

	while (info->drawstart < info->drawend)
	{
		d = info->drawstart * 256 - base->h * 128 + info->lineheight * 128;
		texy = ((d * base->theight[info->texnum]) / info->lineheight) / 256;
		color = base->tex[info->texnum]
		[texy * base->twidth[info->texnum] + info->texx];
		if (info->texnum != 4 || color != 0)
			data[(info->drawstart) * (base->w) + x] = color;
		(info->drawstart)++;
	}
}

void	find_hit(t_cub *base, t_ren *info)
{
	if (info->sidedistx < info->sidedisty)
	{
		info->sidedistx += info->deltadistx;
		info->mapx += info->stepx;
		info->side = 0;
	}
	else
	{
		info->sidedisty += info->deltadisty;
		info->mapy += info->stepy;
		info->side = 1;
	}
	if (base->worldmap[info->mapx][info->mapy] == 1)
		info->hit = base->worldmap[info->mapx][info->mapy];
	if (base->worldmap[info->mapx][info->mapy] == 2)
	{
		info->spritex = info->mapx;
		info->spritey = info->mapy;
	}
}

void	find_height(t_cub *base, t_ren *info)
{
	if (info->side == 0)
		info->perpwalldist = (info->mapx - base->posx
				+ (1 - info->stepx) / 2) / info->raydirx;
	else
		info->perpwalldist = (info->mapy - base->posy
				+ (1 - info->stepy) / 2) / info->raydiry;
	info->lineheight = (int)(base->h / info->perpwalldist);
	info->drawstart = base->h / 2 - info->lineheight / 2;
	if (info->drawstart < 0)
		info->drawstart = 0;
	info->drawend = base->h / 2 + info->lineheight / 2;
	if (info->drawend >= base->h)
		info->drawend = base->h - 1;
}
