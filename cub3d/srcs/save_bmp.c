/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:16:43 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_bmp(t_bmp *bit, t_cub *base)
{
	bit->i_h.bisize = sizeof(t_bih);
	bit->i_h.biwidth = base->w;
	bit->i_h.biheight = base->h;
	bit->i_h.biplanes = 1;
	bit->i_h.bibitcount = 32;
	bit->i_h.bicompression = 0;
	bit->i_h.bisizeimage = base->w * base->h * 4;
	bit->i_h.bixpelspermeter = 0x130B;
	bit->i_h.biypelspermeter = 0x130B;
	bit->i_h.biclrused = 0;
	bit->i_h.biclrimportant = 0;
	bit->f_h.bftype = 0x4D42;
	bit->f_h.bfreserved1 = 0;
	bit->f_h.bfreserved2 = 0;
	bit->f_h.bfsize = sizeof(t_bmp) + bit->i_h.bisizeimage;
	bit->f_h.bfoffbits = sizeof(t_bmp);
}

void	rev_data(uint32_t *data, t_cub *base)
{
	int			idx;
	int			idx2;
	uint32_t	tmp;

	idx = 0;
	while (idx <= base->h / 2)
	{
		idx2 = 0;
		while (idx2 < base->w)
		{
			tmp = data[(base->h - 1 - idx) * base->w + idx2];
			data[(base->h - 1 - idx) * base->w + idx2] =
				data[idx * base->w + idx2];
			data[idx * base->w + idx2] = tmp;
			idx2++;
		}
		idx++;
	}
}

void	init_data(t_cub *base, void **img, uint32_t **data)
{
	int size;
	int bpp;
	int	endian;

	bpp = 32;
	size = base->w;
	endian = 0;
	*data = (uint32_t*)mlx_get_data_addr(*img, &bpp, &size, &endian);
}

void	save_bmp(t_cub *base, void *img)
{
	t_bmp		*bit;
	int			fd;
	uint32_t	*data;

	bit = (t_bmp*)ft_calloc(1, sizeof(t_bmp));
	init_bmp(bit, base);
	fd = open("new.bmp", O_CREAT | O_WRONLY, 0777);
	write(fd, bit, sizeof(t_bmp));
	free(bit);
	init_data(base, &img, &data);
	rev_data(data, base);
	write(fd, data, sizeof(uint32_t) * base->w * base->h);
}
