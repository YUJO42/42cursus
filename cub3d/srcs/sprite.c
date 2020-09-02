/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:16:48 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_sprite_init(t_cub *base, t_ren *info, t_spr *init)
{
	info->spritex -= base->posx;
	info->spritey -= base->posy;
	init->invdet = 1.0 / (base->planex * base->diry
			- base->dirx * base->planey);
	init->transformx = init->invdet * (base->diry * info->spritex
			- base->dirx * info->spritey);
	init->transformy = init->invdet * (-(base->planey * info->spritex)
	+ base->planex * info->spritey);
	init->spritescreenx = (int)((base->w / 2)
			* (1 + init->transformx / init->transformy));
	init->spriteheight = (int)fabs((base->h / init->transformy));
}

void	put_sprite_loop(t_cub *base, t_ren *info, uint32_t *data, t_spr *init)
{
	int			texx;
	int			texy;
	int			d;
	int			idx;

	while (++(init->drawstartx) < init->drawendx)
	{
		texx = (int)(256 * (init->drawstartx
		- (-init->spritewidth / 2 + init->spritescreenx))
		* base->twidth[4] / init->spritewidth) / 256;
		if (init->transformy > 0 && init->drawstartx > 0
		&& init->drawstartx < base->w
		&& init->transformy < info->zbuffer[init->drawstartx])
		{
			idx = init->drawstarty - 1;
			while (++idx < init->drawendy)
			{
				d = idx * 256 - base->h * 128 + init->spriteheight * 128;
				texy = ((d * base->theight[4]) / init->spriteheight) / 256;
				base->color = base->tex[4][base->twidth[4] * texy + texx];
				if (base->color != 0)
					data[idx * base->w + init->drawstartx] = base->color;
			}
		}
	}
}

void	put_sprite(t_cub *base, t_ren *info, uint32_t *data)
{
	t_spr	init;

	put_sprite_init(base, info, &init);
	init.drawstarty = -(init.spriteheight / 2) + base->h / 2;
	if (init.drawstarty < 0)
		init.drawstarty = 0;
	init.drawendy = init.spriteheight / 2 + base->h / 2;
	if (init.drawendy >= base->h)
		init.drawendy = base->h - 1;
	init.spritewidth = (int)fabs((base->h / init.transformy));
	init.drawstartx = -init.spritewidth / 2 + init.spritescreenx;
	if (init.drawstartx < 0)
		init.drawstartx = 0;
	init.drawendx = init.spritewidth / 2 + init.spritescreenx;
	if (init.drawendx >= base->w)
		init.drawendx = base->w - 1;
	(init.drawstartx)--;
	put_sprite_loop(base, info, data, &init);
}
