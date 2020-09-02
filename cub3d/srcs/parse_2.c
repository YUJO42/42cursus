/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 15:16:41 by yujo              #+#    #+#             */
/*   Updated: 2020/09/02 17:16:30 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		parse_color_du(char *line, int *idx2)
{
	int		idx;
	int		ans;
	char	*str;

	idx = 0;
	while (line[*idx2] == ' ' || line[*idx2] == ',')
		(*idx2)++;
	while (line[*idx2] != ' ' && line[*idx2] != ',' && line[*idx2])
	{
		(*idx2)++;
		idx++;
	}
	if (!(str = ft_substr(&line[(*idx2) - idx - 1], 1, idx)))
		do_error(5, &line, 0);
	ans = ft_atoi(str);
	free(str);
	return (ans);
}

void	parse_color(char *line, uint32_t *color)
{
	int	idx;

	idx = 1;
	*color = parse_color_du(line, &idx) * 256 * 256;
	*color += parse_color_du(line, &idx) * 256;
	*color += parse_color_du(line, &idx);
}

int		parse_xpm_du(int *idx2, char *line)
{
	int		idx;
	int		ans;
	char	*str;

	idx = 0;
	while (line[(*idx2)++] != ' ')
		idx++;
	if (!(str = ft_substr(&line[(*idx2) - idx - 1], 0, idx)))
		do_error(5, &line, 0);
	ans = ft_atoi(str);
	free(str);
	return (ans);
}

void	parse_xpm(char *str, t_cub *info, int texnum)
{
	int		fd;
	int		idx;
	char	*line;

	if ((fd = open(str, O_RDONLY, 0777)) < 3)
		do_error(3, &str, 0);
	idx = 0;
	line = NULL;
	while (idx++ < 3)
	{
		get_next_line(fd, &line);
		free(line);
		line = NULL;
	}
	idx = 1;
	if (get_next_line(fd, &line) < 1)
		do_error(6, &str, 0);
	(info->twidth[texnum]) = parse_xpm_du(&idx, line);
	(info->theight[texnum]) = parse_xpm_du(&idx, line);
	(info->tsize[texnum]) = parse_xpm_du(&idx, line);
	(info->tbpp[texnum]) = parse_xpm_du(&idx, line) * 8;
	(info->endian) = 0;
	free(line);
}
