/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:46:35 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 15:30:55 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/cub3d.h"

int		parse_res_du(char *line, int *idx2)
{
	int		idx;
	int		num;
	char	*str;

	idx = 0;
	while (line[*idx2] != ' ' && line[*idx2])
	{
		(*idx2)++;
		idx++;
	}
	if (!(str = ft_substr(&line[*idx2 - idx], 0, idx)))
		do_error(5, &line, 0);
	num = ft_atoi(str);
	free(str);
	return (num);
}

void	parse_res(char *line, t_cub *base)
{
	int	idx2;

	idx2 = 0;
	while (line[idx2] == 'R' || line[idx2] == ' ')
		idx2++;
	base->w = parse_res_du(line, &idx2);
	while (line[idx2] == ' ')
		idx2++;
	base->h = parse_res_du(line, &idx2);
	if (base->w > 2560)
		base->w = 2560;
	if (base->h > 1440)
		base->h = 1440;
}

void	parse_tex(char *line, t_cub *base, char *dir, int texnum)
{
	int		idx;
	int		idx2;
	char	*str;
	void	*image;

	idx = 0;
	idx2 = 0;
	while (line[idx2] == dir[0] || line[idx2] == dir[1] || line[idx2] == ' ')
		idx2++;
	while (line[idx2++])
		idx++;
	if (!(str = ft_substr(&line[idx2 - idx - 1], 0, idx)))
		do_error(5, &line, 0);
	parse_xpm(str, base, texnum);
	image = mlx_xpm_file_to_image(base->mlx, str, &base->twidth[texnum]
	, &base->theight[texnum]);
	base->tex[texnum] = (uint32_t*)mlx_get_data_addr(image, &base->tbpp[texnum]
	, &base->tsize[texnum], &base->endian);
	free(str);
}

void	parse_main_du(char *line, t_cub *base, int *check)
{
	if (line[0] == 'R')
		parse_res(line, base);
	else if (line[0] == 'N' && line[1] == 'O')
		parse_tex(line, base, "NO", 0);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_tex(line, base, "SO", 1);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_tex(line, base, "EA", 2);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_tex(line, base, "WE", 3);
	else if (line[0] == 'S' && line[1] == ' ')
		parse_tex(line, base, "S ", 4);
	else if (line[0] == 'F')
		parse_color(line, &(base->f_color));
	else if (line[0] == 'C')
		parse_color(line, &(base->c_color));
	else
		return ;
	(*check)++;
}

int		parse_main(char *argv, t_cub *base)
{
	int		fd;
	int		idx;
	int		check;
	char	*line;

	idx = 0;
	check = 0;
	line = NULL;
	if ((fd = open(argv, O_RDONLY, 0777)) < 3)
		do_error(2, 0, 0);
	while (get_next_line(fd, &line))
	{
		parse_main_du(line, base, &check);
		if (check > 8)
			do_error(4, &line, 0);
		if (check == 8 && line[0] != 'C' && line[0])
		{
			if (*line)
				base->worldmap[idx++] = ft_strdup(line);
		}
		free(line);
		line = NULL;
	}
	free(line);
	return (idx);
}
