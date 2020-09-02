/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:16:34 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_base(int x, t_cub *base, t_ren *info)
{
	double	camerax;

	camerax = 2 * x / (double)(base->w) - 1;
	info->raydirx = base->dirx + base->planex * camerax;
	info->raydiry = base->diry + base->planey * camerax;
	info->mapx = (int)(base->posx);
	info->mapy = (int)(base->posy);
	info->deltadistx = sqrt(1 + pow(info->raydiry, 2) / pow(info->raydirx, 2));
	info->deltadisty = sqrt(1 + pow(info->raydirx, 2) / pow(info->raydiry, 2));
}

void	init_delta(t_cub *base, t_ren *info)
{
	if (info->raydirx < 0)
	{
		info->stepx = -1;
		info->sidedistx = (base->posx - info->mapx) * info->deltadistx;
	}
	else
	{
		info->stepx = 1;
		info->sidedistx = (info->mapx + 1.0 - base->posx) * info->deltadistx;
	}
	if (info->raydiry < 0)
	{
		info->stepy = -1;
		info->sidedisty = (base->posy - info->mapy) * info->deltadisty;
	}
	else
	{
		info->stepy = 1;
		info->sidedisty = (info->mapy + 1.0 - base->posy) * info->deltadisty;
	}
}

void	main_loop(t_cub *base, t_ren *info, uint32_t *data)
{
	int	x;

	x = 0;
	while (x < base->w)
	{
		info->hit = 0;
		init_base(x, base, info);
		init_delta(base, info);
		while (info->hit == 0)
			find_hit(base, info);
		find_height(base, info);
		info->zbuffer[x] = info->perpwalldist;
		select_tex(base, info);
		put_pixel(x, base, info, data);
		x++;
	}
}

void	get_data(t_cub *base, void **img, uint32_t **data)
{
	int			bpp;
	int			size;
	int			endian;

	size = base->w;
	bpp = 32;
	endian = 0;
	*img = mlx_new_image(base->mlx, base->w, base->h);
	*data = (uint32_t*)mlx_get_data_addr(*img, &bpp, &size, &endian);
}

int		render_main(void *param)
{
	t_ren		info;
	void		*img;
	uint32_t	*data;
	t_cub		*base;

	base = (t_cub*)param;
	get_data(base, &img, &data);
	put_base_color(base, data);
	main_loop(base, &info, data);
	put_sprite(base, &info, data);
	if (base->mode == 1)
		mlx_put_image_to_window(base->mlx, base->win, img, 0, 0);
	else if (base->mode == 2)
		save_bmp(base, img);
	mlx_destroy_image(base->mlx, img);
	return (0);
}
