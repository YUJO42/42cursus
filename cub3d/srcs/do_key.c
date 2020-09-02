/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:05:09 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:05:11 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	do_y(t_cub *base, int mode)
{
	if (mode == 0)
	{
		if (base->worldmap[(int)(base->posx)]
		[(int)(base->posy + base->diry * 0.05)] == 0)
			base->posy += base->diry * 0.05;
	}
	else if (mode == 1)
	{
		if (base->worldmap[(int)(base->posx)]
		[(int)(base->posy - base->diry * 0.05)] == 0)
			base->posy -= base->diry * 0.05;
	}
	else if (mode == 2)
	{
		if (base->worldmap[(int)(base->posx)]
		[(int)(base->posy + base->dirx * 0.05)] == 0)
			base->posy += base->dirx * 0.05;
	}
	else if (mode == 3)
	{
		if (base->worldmap[(int)(base->posx)]
		[(int)(base->posy - base->dirx * 0.05)] == 0)
			base->posy -= base->dirx * 0.05;
	}
}

void	do_x(t_cub *base, int mode)
{
	if (mode == 0)
	{
		if (base->worldmap[(int)(base->posx + base->dirx * 0.05)]
		[(int)(base->posy)] == 0)
			base->posx += base->dirx * 0.05;
	}
	else if (mode == 1)
	{
		if (base->worldmap[(int)(base->posx - base->dirx * 0.05)]
		[(int)(base->posy)] == 0)
			base->posx -= base->dirx * 0.05;
	}
	else if (mode == 2)
	{
		if (base->worldmap[(int)(base->posx - base->diry * 0.05)]
		[(int)(base->posy)] == 0)
			base->posx -= base->diry * 0.05;
	}
	else if (mode == 3)
	{
		if (base->worldmap[(int)(base->posx + base->diry * 0.05)]
		[(int)(base->posy)] == 0)
			base->posx += base->diry * 0.05;
	}
}

void	do_turn(t_cub *base, double rad)
{
	double olddirx;
	double oldplanex;

	olddirx = base->dirx;
	base->dirx = base->dirx * cos(rad) - base->diry * sin(rad);
	base->diry = olddirx * sin(rad) + base->diry * cos(rad);
	oldplanex = base->planex;
	base->planex = base->planex * cos(rad) - base->planey * sin(rad);
	base->planey = oldplanex * sin(rad) + base->planey * cos(rad);
}

int		do_key(int key, void *param)
{
	int		mode;
	t_cub	*base;

	base = (t_cub*)param;
	mode = -1;
	if (key == 53)
		exit_proc(base);
	if (key == 13)
		mode = 0;
	if (key == 1)
		mode = 1;
	if (key == 0)
		mode = 2;
	if (key == 2)
		mode = 3;
	if (mode > -1)
	{
		do_x(base, mode);
		do_y(base, mode);
	}
	if (key == 124)
		do_turn(base, -0.03);
	if (key == 123)
		do_turn(base, 0.03);
	return (0);
}
