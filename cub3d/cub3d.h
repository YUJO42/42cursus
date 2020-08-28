/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:57:24 by yujo              #+#    #+#             */
/*   Updated: 2020/08/26 19:37:28 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HEADER
# define CUB3D_HEADER

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

struct	Sprite
{
	double		x;
	double		y;
	int			texture;
};

struct Sprite	sprite[numSprites] =
{
	{20.5, 11.5, 10}, //green light in front of playerstart
	//green lights in every room
	{18.5,4.5, 10},
	{10.0,4.5, 10},
	{10.0,12.5,10},
	{3.5, 6.5, 10},
	{3.5, 20.5,10},
	{3.5, 14.5,10},
	{14.5,20.5,10},

	//row of pillars in front of wall: fisheye test
	{18.5, 10.5, 9},
	{18.5, 11.5, 9},
	{18.5, 12.5, 9},

	//some barrels around the map
	{21.5, 1.5, 8},
	{15.5, 1.5, 8},
	{16.0, 1.8, 8},
	{16.2, 1.2, 8},
	{3.5,  2.5, 8},
	{9.5, 15.5, 8},
	{10.0, 15.1,8},
	{10.5, 15.8,8},
};

int		spriteOrder[numSprites];
double	spriteDistance[numSprites];

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_esc;
	t_img	img;
	int		buf[height][width];
	double	zBuffer[width];
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

typedef struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include "keymap.h"
# include <math.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17

# define texWidth 64
# define texHeight 64

# define mapWidth 24
# define mapHeight 24

# define width 640
# define height 480

# define numSprites 19

# define PI 3.141592

#endif