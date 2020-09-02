/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:50:01 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 16:53:33 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CUB3D_H
#	define CUB3D_H

#	include "../includes/get_next_line.h"
#	include "../libft/libft.h"
#	include <mlx.h>
#	include <stdlib.h>
#	include <unistd.h>
#	include <fcntl.h>
#	include <math.h>
#	include <stdint.h>
#	include <errno.h>
#	include <string.h>

#include <stdio.h>

typedef struct	s_cub_3d
{
	int			check;
	int			mode;
	char		dirword;
	int			maplen;
	int			w;
	int			h;
	void		*mlx;
	void		*win;
	void		*image;
	uint32_t	*tex[5];
	char		*worldmap[100];
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	uint32_t	c_color;
	uint32_t	f_color;
	int			twidth[5];
	int			theight[5];
	int			tbpp[5];
	int			tsize[5];
	int			endian;
	uint32_t	color;
	void		*img;
}				t_cub;

typedef struct	s_render
{
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	int		hit;
	double	sidedistx;
	double	sidedisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	int		texx;
	double	wallx;
	double	zbuffer[2160];
	double	spritedistance;
	double	spritex;
	double	spritey;
}				t_ren;

typedef struct	s_sprite
{
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		spritewidth;
	int		drawstartx;
	int		drawstarty;
	int		drawendx;
	int		drawendy;
}				t_spr;

#pragma pack(push, 1)

typedef struct	s_bitmapfileheader
{
	uint16_t	bftype;
	uint32_t	bfsize;
	uint16_t	bfreserved1;
	uint16_t	bfreserved2;
	uint32_t	bfoffbits;
}				t_bfh;

typedef struct	s_bitmapinfoheader
{
	uint32_t	bisize;
	int32_t		biwidth;
	int32_t		biheight;
	uint16_t	biplanes;
	uint16_t	bibitcount;
	uint32_t	bicompression;
	uint32_t	bisizeimage;
	int32_t		bixpelspermeter;
	int32_t		biypelspermeter;
	uint32_t	biclrused;
	uint32_t	biclrimportant;
}				t_bih;

typedef struct	s_bitmap
{
	t_bfh	f_h;
	t_bih	i_h;
}				t_bmp;

#pragma pack(pop)

int				parse_main(char *argv, t_cub *base);

int				render_main(void *param);

int				do_key(int key, void *param);

void			put_sprite(t_cub *base, t_ren *info, uint32_t *data);

void			save_bmp(t_cub *base, void *img);

int				exit_proc(void *param);

void			do_error(int num, char **line, t_cub *base);

void			map_check(char **worldmap, t_cub *base);

void			preproc_map(char **worldmap, t_cub *base);

void			parse_color(char *line, uint32_t *color);

void			parse_xpm(char *str, t_cub *info, int texnum);

void			main_loop(t_cub *base, t_ren *info, uint32_t *data);

void			select_tex(t_cub *base, t_ren *info);

void			put_base_color(t_cub *base, uint32_t *data);

void			put_pixel(int x, t_cub *base, t_ren *info, uint32_t *data);

void			find_hit(t_cub *base, t_ren *info);

void			find_height(t_cub *base, t_ren *info);

#	endif
