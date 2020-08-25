/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:58:37 by yujo              #+#    #+#             */
/*   Updated: 2020/08/25 15:07:20 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	map_read(t_window *window, char *path)
{
	char	*map_oneline;
	map_oneline = read_map_oneline(path);
	window->row_count = map_check_row_num(map_oneline);
	window->column_count = map_check_col_num(map_oneline);
	window->total_unit = window->row_count * window->column_count;
	window->map = ft_split(map_oneline, '\n');
	map_convert_spaces(window->map, window->row_count, window->column_count);
	int i =0;
	while (window->map[i])
		printf("%s\n",window->map[i++]);
}