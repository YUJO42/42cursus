/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujo <yujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 15:48:16 by yujo              #+#    #+#             */
/*   Updated: 2020/08/29 15:51:19 by yujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_info	read_cub_file(char *path)
{
	t_info		    game_info;
	int				type_err;
	int				map_err;
	int				map_widthy_err;
	int				fd;

	fd = open_cub_file(path);
	game_info = init_game_info();
	type_err = get_type(fd, &game_info);
	map_widthy_err = get_map_widthy(fd, &game_info);
	close(fd);
	fd = open(path, O_RDONLY);
	map_err = get_map(fd, &game_info);
	if (type_err == ERROR || map_widthy_err == ERROR || map_err == ERROR
	|| still_has_line(fd) || check_map(&game_info) == ERROR)
	{
		free_game_info(&game_info);
		exit_with_errmsg("invalid cub file");
	}
	return (game_info);
}
